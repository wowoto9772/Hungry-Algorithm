//
//#include <stdio.h>
//#include <memory.h>
//#include <limits.h>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//int cap[403][403];
//int limit[403];
//int flow[403][403];
//char plt[24][24];
//char liz[24][24];
//
//int min(int a, int b){ return a < b ? a : b; }
//int abs(int a){ return a < -a ? -a : a; }
//
//int maximum_flow(int s, int e, vector < vector<int> > &conf){ // 0, 401
//	memset(flow, 0, sizeof(flow));
//
//	int ret = 0;
//	while (true){
//		int p[403];
//		memset(p, 0xff, sizeof(p));
//		queue <int> q;
//		q.push(s);
//
//		while (!q.empty() && p[e] == -1){
//			int c = q.front(); q.pop();
//			for (int i = 1; i <= e; i++){
//				if (cap[c][i] - flow[c][i] > 0 && p[i] == -1){
//					if (i < e){
//						int x = 0;
//						for (int j = 0; j < conf[i].size(); j++){
//							x += flow[conf[i][j]][i];
//						}
//						if (x >= limit[i] && c){
//							continue;
//						}
//					}
//					p[i] = c;
//					q.push(i);
//				}
//			}
//		}
//
//		if (p[e] == -1)return ret;
//
//		int f = e;
//		int cf = INT_MAX;
//		while (p[f] != -1){
//			cf = min(cf, cap[p[f]][f] - flow[p[f]][f]);
//			f = p[f];
//		}
//
//		f = e;
//		while (p[f] != -1){
//			flow[p[f]][f] += cf;
//			flow[f][p[f]] -= cf;
//			f = p[f];
//		}
//
//		ret += cf;
//	}
//}
//
//
//int dst(int x, int y, int x2, int y2){
//	return abs(x - x2) + abs(y - y2);
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	int tc = 0;
//	while (t--){
//		int r, d, c;
//		scanf("%d %d", &r, &d);
//
//		int n = 0;
//
//		for (int i = 1; i <= r; i++)scanf("%s", plt[i] + 1);
//		for (int i = 1; i <= r; i++)scanf("%s", liz[i] + 1);
//		c = strlen(plt[1] + 1);
//
//		memset(cap, 0, sizeof(cap));
//
//		vector < vector <int> > conf;
//		conf.resize(r * c + 1);
//
//		for (int i = 1; i <= r; i++){
//			for (int j = 1; j <= c; j++){
//				int k = (i - 1) * c + j;
//				limit[k] = plt[i][j] - '0';
//				if (liz[i][j] == 'L'){ // linked to source
//					cap[0][k] = 1;
//					n++;
//				}
//				
//				for (int a = 0; a <= r + 1; a++){
//					for (int b = 0; b <= c + 1; b++){
//						if (i == a && b == j)continue;
//						int l = dst(i, j, a, b);
//						if (l <= d){
//							int k2 = (a - 1) * c + b;
//
//							int y = plt[a][b] - '0';
//							if (y > 0){
//								cap[k][k2] = y;
//								conf[k2].push_back(k);
//							}
//						}
//					}
//				}
//			}
//		}
//
//		printf("Case #%d: ", ++tc);
//		int ans = n - maximum_flow(0, r * c + 1, conf);
//		if (ans == 0)printf("no lizard was ");
//		else if (ans == 1)printf("1 lizard was ");
//		else{
//			printf("%d lizards were ", ans);
//		}
//		printf("left behind.\n");
//	}
//}

#include <stdio.h>
#include <memory.h>
#include <limits.h>
#include <queue>

using namespace std;

int p[804];
int cap[804][804];
int flow[804][804];
char plt[24][24];
char liz[24][24];

int min(int a, int b){ return a < b ? a : b; }
int abs(int a){ return a < -a ? -a : a; }

int maximum_flow(int s, int e){
	memset(flow, 0, sizeof(flow));

	int ret = 0;
	while (true){
		memset(p, 0xff, sizeof(p));
		queue <int> q;
		q.push(s);

		while (!q.empty() && p[e] == -1){
			int c = q.front(); q.pop();
			for (int i = 1; i <= e; i++){
				if (cap[c][i] - flow[c][i] > 0 && p[i] == -1){
					p[i] = c;
					q.push(i);
				}
			}
		}

		if (p[e] == -1)return ret;

		int f = e;
		int cf = INT_MAX;
		while (p[f] != -1){
			cf = min(cf, cap[p[f]][f] - flow[p[f]][f]);
			f = p[f];
		}

		f = e;
		while (p[f] != -1){
			flow[p[f]][f] += cf;
			flow[f][p[f]] -= cf;
			f = p[f];
		}

		ret += cf;
	}
}

int dst(int x, int y, int x2, int y2){
	return abs(x - x2) + abs(y - y2);
}

int main()
{
	int t;
	scanf("%d", &t);

	int tc = 0;
	while (t--){
		int r, d, c;
		scanf("%d %d", &r, &d);

		int n = 0;

		for (int i = 1; i <= r; i++)scanf("%s", plt[i] + 1);
		for (int i = 1; i <= r; i++)scanf("%s", liz[i] + 1);
		c = strlen(plt[1] + 1);

		memset(cap, 0, sizeof(cap));
		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= c; j++){
				if (plt[i][j] == '0')continue;
				int k = (i - 1) * c + j;
				if (liz[i][j] == 'L'){ // linked to source
					cap[0][k] = 1;
					n++;
				}
				int y = plt[i][j] - '0';
				cap[k][r*c + k] = y; // add special node
				if (i <= d || j <= d || r + 1 - i <= d || c + 1 - j <= d){
					cap[r*c + k][2 * r*c + 1] = INT_MAX;
				}
				for (int a = 1; a <= r; a++){
					for (int b = 1; b <= c; b++){
						if (plt[a][b] == '0')continue;						if (a == i && b == j)continue;
						int l = dst(i, j, a, b);
						if (l <= d){
							int k2 = (a - 1) * c + b;
							cap[r*c + k][k2] = INT_MAX;
						}
					}
				}
			}
		}

		printf("Case #%d: ", ++tc);
		int ans = n - maximum_flow(0, 2 * r*c + 1);
		if (ans == 0)printf("no lizard was ");
		else if (ans == 1)printf("1 lizard was ");
		else{
			printf("%d lizards were ", ans);
		}
		printf("left behind.\n");
	}
}

/*
100
3 1
000
100
000
...
LL.
...
3 1
000
210
000
...
LL.
...
3 1
111
111
111
LLL
LLL
LLL
*/