//#include <stdio.h>
//#include <queue>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//int dr[] = { 0, 0, -1, 1 };
//int dc[] = { -1, 1, 0, 0 };
//
//class ele{
//public:
//	int r, c;
//	ele(){}
//	ele(int a, int b){ r = a, c = b; }
//};
//
//int g[103][103];
//int a[103][103];
//
//int main(){
//	int n;
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)scanf("%d", &a[i][j]);
//		
//	int top = 0;
//	queue <ele> q;
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++){
//			if (g[i][j])continue;
//			if (a[i][j]){
//				q.emplace(i, j);
//
//				++top;
//
//				while (!q.empty()){
//					ele qq = q.front();
//					q.pop();
//					for (int k = 0; k < 4; k++){
//						int nr = qq.r + dr[k];
//						int nc = qq.c + dc[k];
//						if (nr < 1 || nc < 1 || nr > n || nc > n)continue;
//						if (a[nr][nc]){
//							if (g[nr][nc])continue;
//							g[nr][nc] = top;
//							q.emplace(nr, nc);
//						}
//					}
//				}
//			}
//		}
//	}
//
////	int d[103][103];
////	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)d[i][j] = 10003;
//
//	int ans = 10003;
//
//	map <int, map<int, map<int, bool> > > chk;
//
//	queue <ele> p;
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++){
//			if (g[i][j]){
//				q.emplace(i, j);
//				p.emplace(g[i][j], 0);
//
//				while (!q.empty()){
//					ele qq = q.front(); q.pop();
//					ele pp = p.front(); p.pop();
//					pp.c++;
//
//					if (pp.c >= ans)break;
//
//					for (int k = 0; k < 4; k++){
//						int nr = qq.r + dr[k];
//						int nc = qq.c + dc[k];
//						if (nr < 1 || nc < 1 || nr > n || nc > n)continue;
//						if (g[nr][nc] != pp.r){
//							
//							if (chk[pp.r][nr][nc])continue;
//
//							chk[pp.r][nr][nc] = true;
//							
//							if (g[nr][nc]){
//								//d[pp.r][g[nr][nc]] = min(d[pp.r][g[nr][nc]], pp.c);
//								ans = min(ans, pp.c);
//							}
//
//							q.emplace(nr, nc);
//							p.emplace(pp.r, pp.c);
//						}
//					}
//				}
//			}
//		}
//	}
//
//	printf("%d\n", ans - 1);
//}

#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

class ele{
public:
	int r, c;
	ele(){}
	ele(int a, int b){ r = a, c = b; }
};

int g[103][103];
int a[103][103];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	int top = 0;
	queue <ele> q;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (g[i][j] || !a[i][j])continue;

			q.emplace(i, j);
			g[i][j] = ++top;

			while (!q.empty()){
				ele qq = q.front();
				q.pop();
				for (int k = 0; k < 4; k++){
					int nr = qq.r + dr[k];
					int nc = qq.c + dc[k];
					if (nr < 1 || nc < 1 || nr > n || nc > n)continue;
					if (g[nr][nc])continue;
					if (!a[nr][nc])continue;

					g[nr][nc] = top;
					q.emplace(nr, nc);
				}
			}
		}
	}

	int ans = 201;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (g[i][j]){
				for (int x = 1; x <= n; x++){
					for (int y = 1; y <= n; y++){
						if (g[x][y]){
							if (g[i][j] != g[x][y]){
								ans = min(abs(x - i) + abs(y - j) - 1, ans);
							}
						}
					}
				}
			}
		}
	}

	printf("%d\n", ans);
}