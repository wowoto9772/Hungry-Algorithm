//#include <stdio.h>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
//int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//int m[22][22];
//int n, l;
//
//class ele{
//public:
//	int i, j;
//}psh, pop;
//
//map <int, map<int, map<vector <int>, int> > > dp;
//vector <ele> nxt[22][22][10];
//int limit;
//
//int dy(int r, int c, vector <int> make){
//	if (dp[r][c].count(make) != 0)return dp[r][c][make];
//
//	dp[r][c][make] = 0;
//	int len = make.size();
//	if (len == l){
//		bool unpal = false;
//		for (int i = 0; !unpal && i < len / 2; i++){
//			if (make[i] != make[len - 1 - i])unpal = true;
//		}
//		if (!unpal){ // is palindrome
//			dp[r][c][make] = 1;
//		}
//
//		return dp[r][c][make];
//	}
//
//	if (len > l / 2 && l % 2){
//		int ele = l - len;
//		ele--;
//		for (int i = 0; i < nxt[r][c][make[ele]].size(); i++){
//			vector <int> npsh = make;
//
//			npsh.push_back(make[ele]);
//			psh = nxt[r][c][make[ele]][i];
//			dp[r][c][make] += dy(psh.i, psh.j, npsh);
//		}
//	}
//	else if (len >= l / 2 && l % 2 == 0){
//		int ele = l - len;
//		ele--;
//		for (int i = 0; i < nxt[r][c][make[ele]].size(); i++){
//			vector <int> npsh = make;
//
//			npsh.push_back(make[ele]);
//			psh = nxt[r][c][make[ele]][i];
//			dp[r][c][make] += dy(psh.i, psh.j, npsh);
//		}
//	}
//	else{
//		for (int i = 0; i < 8; i++){
//			int nr = r + dr[i];
//			int nc = c + dc[i];
//			if (nr <= 0 || nc <= 0 || nc > n || nr > n)continue;
//			vector <int> npsh = make;
//			npsh.push_back(m[nr][nc]);
//			dp[r][c][make] += dy(nr, nc, npsh);
//		}
//	}
//
//	printf("%d %d %d\n", r, c, dp[r][c][make]);
//
//	return dp[r][c][make];
//}
//
//int main(){
//	scanf("%d %d", &n, &l);
//
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++){
//			scanf("%d", &m[i][j]);
//		}
//	}
//
//	if (l % 2)limit = l / 2 + 1;
//	else{
//		limit = l / 2;
//	}
//
//	int ans = 0;
//
//
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++){
//			for (int k = 0; k < 8; k++){
//				int ni = i + dr[k];
//				int nj = j + dc[k];
//				if (ni <= 0 || nj <= 0 || ni > n || nj > n)continue;
//				nxt[i][j][m[ni][nj]].push_back({ ni, nj });
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++){
//			vector <int> a(1);
//			a[0] = m[i][j];
//			ans += dy(i, j, a);
//		}
//	}
//
//	printf("%d\n", ans);
//}

//
//#include <stdio.h>
//#include <memory.h>
//#include <vector>
//
//using namespace std;
//
//class ele{
//public:
//	int i, j;
//}psh, pop;
//
//int dp[22][22][22][22][22];
//vector <ele> nxt[22][22][10];
//int A(int a){ return a < -a ? -a : a; }
//
//int dy(int r, int c, int a, int b, int l){
//	if (l == 1){
//		if (r == a && c == b)return 1;
//		return 0;
//	}
//	else if (l == 2){
//		if (r == a && c == b)return 0;
//		else if (A(r - a) <= 1 && A(c - b) <= 1)return 2;
//		return 0;
//	}
//	if (dp[r][c][a][b][l] != -1)return dp[r][c][a][b][l];
//
//	dp[r][c][a][b][l] = 0;
//
//	bool chk[22][22][22][22] = { 0 };
//	for (int i = 0; i <= 9; i++){
//		for (int j = 0; j < nxt[r][c][i].size(); j++){
//			psh = nxt[r][c][i][j];
//			for (int k = 0; k < nxt[a][b][i].size(); k++){
//				pop = nxt[a][b][i][k];
//				if (!chk[psh.i][psh.j][pop.i][pop.j]){
//					dp[r][c][a][b][l] += dy(psh.i, psh.j, pop.i, pop.j, l - 2);
//					chk[psh.i][psh.j][pop.i][pop.j] = chk[pop.i][pop.j][psh.i][psh.j] = true;
//				}
//			}
//		}
//	}
//
//	if (l % 2 && (r != a || c != b))dp[r][c][a][b][l] *= 2;
//	printf("%d %d %d %d %d %d\n", r, c, a, b, l, dp[r][c][a][b][l]);
//
//	return dp[r][c][a][b][l];
//}
//
//int main(){
//	int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
//	int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//	int m[22][22];
//	int N, L;
//	scanf("%d %d", &N, &L);
//
//	for (int i = 1; i <= N; i++){
//		for (int j = 1; j <= N; j++){
//			scanf("%d", &m[i][j]);
//		}
//	}
//
//	int ans = 0;
//
//	for (int i = 1; i <= N; i++){
//		for (int j = 1; j <= N; j++){
//			for (int k = 0; k < 8; k++){
//				int ni = i + dr[k];
//				int nj = j + dc[k];
//				if (ni <= 0 || nj <= 0 || ni > N || nj > N)continue;
//				nxt[i][j][m[ni][nj]].push_back({ ni, nj });
//			}
//		}
//	}
//
//	memset(dp, 0xff, sizeof(dp));
//
//	bool chk[22][22][22][22] = { 0 };
//	for (int i = 1; i <= N; i++){
//		for (int j = 1; j <= N; j++){
//			for (int a = 1; a <= N; a++){
//				for (int b = 1; b <= N; b++){
//					if (m[i][j] == m[a][b] && !chk[i][j][a][b]){
//						chk[i][j][a][b] = true;
//						chk[a][b][i][j] = true;
//						ans += dy(i, j, a, b, L);
//					}
//				}
//			}
//		}
//	}
//
//	printf("%d\n", ans);
//}


//#include <stdio.h>
//#include <memory.h>
//#include <vector>
//
//using namespace std;
//
//class ele{
//public:
//	int i, j;
//}psh, pop;
//
//int dp[22][22][22][22][22];
//vector <ele> nxt[22][22][10];
//int A(int a){ return a < -a ? -a : a; }
//int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
//int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//
//int dy(int r, int c, int a, int b, int l){
//	if (dp[r][c][a][b][l] != -1)return dp[r][c][a][b][l];
//
//	dp[r][c][a][b][l] = 0;
//
//	if (l == 1){
//		if (r == a && c == b)return dp[r][c][a][b][l] = 1;
//		return 0;
//	}
//	else if (l == 2){
//		if (r == a && c == b)return 0;
//		else if (A(r - a) <= 1 && A(c - b) <= 1)return dp[r][c][a][b][l] = 1;
//		return 0;
//	}
//
//	for (int i = 0; i <= 9; i++){
//		for (int j = 0; j < nxt[r][c][i].size(); j++){
//			psh = nxt[r][c][i][j];
//			for (int k = 0; k < nxt[a][b][i].size(); k++){
//				pop = nxt[a][b][i][k];
//				dp[r][c][a][b][l] += dy(psh.i, psh.j, pop.i, pop.j, l - 2);
//			}
//		}
//	}
//
////	printf("%d %d %d %d %d %d\n", r, c, a, b, l, dp[r][c][a][b][l]);
//
//	return dp[r][c][a][b][l];
//}
//
//int main(){
//	int m[22][22];
//	int N, L;
//	scanf("%d %d", &N, &L);
//
//	for (int i = 1; i <= N; i++){
//		for (int j = 1; j <= N; j++){
//			scanf("%d", &m[i][j]);
//		}
//	}
//
//	if (L == 1){
//		printf("%d\n", N*N);
//		return 0;
//	}
//
//	int ans = 0;
//
//	for (int i = 1; i <= N; i++){
//		for (int j = 1; j <= N; j++){
//			for (int k = 0; k < 8; k++){
//				int ni = i + dr[k];
//				int nj = j + dc[k];
//				if (ni < 1 || nj < 1 || ni > N || nj > N)continue;
//				nxt[i][j][m[ni][nj]].push_back({ ni, nj });
//			}
//		}
//	}
//
//	memset(dp, 0xff, sizeof(dp));
//	for (int i = 1; i <= N; i++){
//		for (int j = 1; j <= N; j++){
//			for (int a = 1; a <= N; a++){
//				for (int b = 1; b <= N; b++){
//					if (m[i][j] == m[a][b]){
//						ans += dy(i, j, a, b, L);
//					}
//				}
//			}
//		}
//	}
//
//	printf("%d\n", ans);
//}



//#include <stdio.h>
//#include <memory.h>
//#include <vector>
//
//using namespace std;
//
//class ele{
//public:
//	int i, j;
//}psh, pop;
//
//int dp[22][22][22][22][22];
//vector <ele> nxt[22][22][10];
//const int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
//const int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//
//int dy(int r, int c, int a, int b, int l){
//	if (!l)return 1;
//	if (dp[r][c][a][b][l] != -1)return dp[r][c][a][b][l];
//
//	dp[r][c][a][b][l] = 0;
//
//	//printf("%d %d %d %d %d\n", r, c, a, b, l);
//
//	bool chk[22][22][22][22] = { 0 };
//	for (int i = 0; i <= 9; i++){
//		for (int j = 0; j < nxt[r][c][i].size(); j++){
//			psh = nxt[r][c][i][j];
//			for (int k = 0; k < nxt[a][b][i].size(); k++){
//				pop = nxt[a][b][i][k];
//				if (chk[psh.i][psh.j][pop.i][pop.j])continue;
//				//printf("%d %d %d %d\n", psh.i, psh.j, pop.i, pop.j);
//				dp[r][c][a][b][l] += dy(psh.i, psh.j, pop.i, pop.j, l - 2);
//				chk[psh.i][psh.j][pop.i][pop.j] = chk[pop.i][pop.j][psh.i][psh.j] = true;
//			}
//		}
//	}
//
//	printf("%d %d %d %d %d %d\n", r, c, a, b, l, dp[r][c][a][b][l]);
//
//	return dp[r][c][a][b][l];
//}
//
//int main(){
//	int m[22][22];
//	int N, L;
//	scanf("%d %d", &N, &L);
//
//	for (int i = 1; i <= N; i++){
//		for (int j = 1; j <= N; j++){
//			scanf("%d", &m[i][j]);
//		}
//	}
//
//	int ans = 0;
//
//	for (int i = 1; i <= N; i++){
//		for (int j = 1; j <= N; j++){
//			for (int k = 0; k < 8; k++){
//				int ni = i + dr[k];
//				int nj = j + dc[k];
//				if (ni < 1 || nj < 1 || ni > N || nj > N)continue;
//				nxt[i][j][m[ni][nj]].push_back({ ni, nj });
//			}
//		}
//	}
//
//	memset(dp, 0xff, sizeof(dp));
//	bool chk[22][22][22][22] = { 0 };
//	for (int i = 1; i <= N; i++){
//		for (int j = 1; j <= N; j++){
//			if (L % 2 == 0){
//				for (int x = 0; x < 8; x++){
//					int a = i + dr[x];
//					int b = j + dc[x];
//					if (a < 1 || b < 1 || a > N || b > N)continue;
//					if (chk[i][j][a][b])continue;
//					if (m[i][j] == m[a][b]){
//						ans += dy(i, j, a, b, L - 2);
//						chk[i][j][a][b] = chk[a][b][i][j] = true;
//					}
//				}
//			}
//			else{
//				ans += dy(i, j, i, j, L-1);
//			}
//		}
//	}
//
//	printf("%d\n", ans);
//}
//

#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;

int dp[22][22][22][22][22];
const int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int m[22][22];
int N, L;

int dy(int r, int c, int a, int b, int l){
	if (!l)return 1;
	if (dp[r][c][a][b][l] != -1)return dp[r][c][a][b][l];

	dp[r][c][a][b][l] = 0;

	for (int i = 0; i < 8; i++){
		int nr = r + dr[i];
		if (nr < 1 || nr > N)continue;
		int nc = c + dc[i];
		if (nc < 1 || nc > N)continue;
		for (int j = 0; j < 8; j++){
			int na = a + dr[j];
			if (na < 1 || na > N)continue;
			int nb = b + dc[j];
			if (nb < 1 || nb > N)continue;
			if (m[nr][nc] == m[na][nb]){
				dp[r][c][a][b][l] += dy(nr, nc, na, nb, l - 2);
			}
		}
	}

	return dp[r][c][a][b][l];
}

int main(){
	scanf("%d %d", &N, &L);

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			scanf("%d", &m[i][j]);
		}
	}

	int ans = 0;

	memset(dp, 0xff, sizeof(dp));
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (L % 2 == 0){
				for (int x = 0; x < 8; x++){
					int a = i + dr[x];
					int b = j + dc[x];
					if (a < 1 || b < 1 || a > N || b > N)continue;
					if (m[i][j] == m[a][b]){
						ans += dy(i, j, a, b, L - 2);
					}
				}
			}
			else{
				ans += dy(i, j, i, j, L - 1);
			}
		}
	}

	printf("%d\n", ans);
}

//AC
//#include <stdio.h>
//#include <memory.h>
//#include <vector>
//
//using namespace std;
//
//int N, L;
//int m[22][22];
//
//int dp[22][22][22][22][22];
//int A(int a){ return a < -a ? -a : a; }
//int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
//int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//
//int dy(int r, int c, int a, int b, int l){
//	if (dp[r][c][a][b][l] != -1)return dp[r][c][a][b][l];
//
//	dp[r][c][a][b][l] = 0;
//
//	if (l == 1){
//		if (r == a && c == b)return dp[r][c][a][b][l] = 1;
//		return 0;
//	}
//	else if (l == 2){
//		if (r == a && c == b)return 0;
//		else if (A(r - a) <= 1 && A(c - b) <= 1)return dp[r][c][a][b][l] = 1;
//		return 0;
//	}
//
//	for (int i = 0; i < 8; i++){
//		int nr = r + dr[i];
//		if (nr < 1 || nr > N)continue;
//		int nc = c + dc[i];
//		if (nc < 1 || nc > N)continue;
//		for (int j = 0; j < 8; j++){
//			int na = a + dr[j];
//			if (na < 1 || na > N)continue;
//			int nb = b + dc[j];
//			if (nb < 1 || nb > N)continue;
//			if (m[nr][nc] == m[na][nb]){
//				dp[r][c][a][b][l] += dy(nr, nc, na, nb, l - 2);
//			}
//		}
//	}
//
//	return dp[r][c][a][b][l];
//}
//
//int main(){
//	scanf("%d %d", &N, &L);
//
//	for (int i = 1; i <= N; i++){
//		for (int j = 1; j <= N; j++){
//			scanf("%d", &m[i][j]);
//		}
//	}
//
//	int ans = 0;
//
//	memset(dp, 0xff, sizeof(dp));
//	for (int i = 1; i <= N; i++){
//		for (int j = 1; j <= N; j++){
//			for (int a = 1; a <= N; a++){
//				for (int b = 1; b <= N; b++){
//					if (m[i][j] == m[a][b]){
//						ans += dy(i, j, a, b, L);
//					}
//				}
//			}
//		}
//	}
//
//	printf("%d\n", ans);
//}

/*
#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;

class ele{
public:
int i, j;
}psh, pop;

int N, L;
int m[22][22];

int dp[22][22][22][22][22];
int A(int a){ return a < -a ? -a : a; }
int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

vector <ele> nxt[22][22][10];

int dy(int r, int c, int a, int b, int l){
if (dp[r][c][a][b][l] != -1)return dp[r][c][a][b][l];

dp[r][c][a][b][l] = 0;

if (l == 1){
if (r == a && c == b)return dp[r][c][a][b][l] = 1;
return 0;
}
else if (l == 2){
if (r == a && c == b)return 0;
else if (A(r - a) <= 1 && A(c - b) <= 1)return dp[r][c][a][b][l] = 1;
return 0;
}

for (int i = 0; i <= 9; i++){
for (int j = 0; j < nxt[r][c][i].size(); j++){
psh = nxt[r][c][i][j];
for (int k = 0; k < nxt[a][b][i].size(); k++){
pop = nxt[a][b][i][k];
dp[r][c][a][b][l] += dy(psh.i, psh.j, pop.i, pop.j, l - 2);
}
}
}

return dp[r][c][a][b][l];
}

int main(){
scanf("%d %d", &N, &L);

for (int i = 1; i <= N; i++){
for (int j = 1; j <= N; j++){
scanf("%d", &m[i][j]);
}
}

for (int i = 1; i <= N; i++){
for (int j = 1; j <= N; j++){
for (int k = 0; k < 8; k++){
int ni = i + dr[k];
if (ni < 1 || ni > N)continue;
int nj = j + dc[k];
if (nj < 1 || nj > N)continue;
nxt[i][j][m[ni][nj]].push_back({ ni, nj });
}
}
}

int ans = 0;

memset(dp, 0xff, sizeof(dp));
for (int i = 1; i <= N; i++){
for (int j = 1; j <= N; j++){
for (int a = 1; a <= N; a++){
for (int b = 1; b <= N; b++){
if (m[i][j] == m[a][b]){
ans += dy(i, j, a, b, L);
}
}
}
}
}

printf("%d\n", ans);
}
*/