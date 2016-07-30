//#include <stdio.h>
//#include <limits.h>
//#include <memory.h>
//
//#include <vector>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//class ele{
//public:
//	int a, c;
//};
//
//vector <vector<int> > F, R, G;
//
//bool v[500003];
//int stk[500003], stp;
//void DFN(int c){
//	v[c] = true;
//
//	for (int i = 0; i < F[c].size(); i++){
//		int n = F[c][i];
//		if (!v[n])DFN(n);
//	}
//
//	stk[++stp] = c;
//}
//int mny[500003];
//int g[500003], gtp, cst[500003];
//void CYC(int c){
//	g[c] = gtp;
//	cst[gtp] += mny[c];
//	for (int i = 0; i < R[c].size(); i++){
//		int n = R[c][i];
//		if (!g[n])CYC(n);
//	}
//}
//int dp[500003];
//vector <bool> e;
//
//int dy(int c){
//	if (dp[c] != -1)return dp[c];
//
//	if (e[c])dp[c] = 0; // end point
//	else
//		dp[c] = -4001; // not end point but can't go anywhere
//
//	for (int i = 0; i < G[c].size(); i++){
//		if (dy(G[c][i]) < 0)continue;
//		dp[c] = max(dp[c], dy(G[c][i]) + cst[G[c][i]]);
//	}
//
//	return dp[c];
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n, m;
//		scanf("%d %d", &n, &m);
//
//		F.resize(n + 1), R.resize(n + 1);
//		for (int i = 1; i <= m; i++){
//			int a, b;
//			scanf("%d %d", &a, &b);
//			F[a].push_back(b);
//			R[b].push_back(a);
//		}
//
//		stp = 0;
//		for (int i = 1; i <= n; i++){
//			scanf("%d", &mny[i]);
//			if (!v[i])DFN(i);
//		}
//
//		gtp = 0;
//		for (int i = stp; i >= 1; i--){
//			if (!g[stk[i]]){
//				gtp++;
//				cst[gtp] = 0;
//				CYC(stk[i]);
//			}
//		}
//
//		G.resize(gtp + 1);
//		map <int, map<int, bool> >chk;
//		for (int i = 1; i <= n; i++){
//			for (int j = 0; j < F[i].size(); j++){
//				int k = F[i][j];
//				if (chk[g[i]][g[k]])continue;
//				else{
//					if (g[i] != g[k]){
//						G[g[i]].push_back(g[k]);
//						chk[g[i]][g[k]] = true;
//					}
//				}
//			}
//		}
//
//		int s, p;
//		scanf("%d %d", &s, &p);
//		
//		e.resize(gtp + 1);
//		for (int i = 1; i <= p; i++){
//			int a;
//			scanf("%d", &a);
//			e[g[a]] = true;
//		}
//
//		memset(dp, 0xff, sizeof(dp));
//		printf("%d\n", dy(g[s]) + cst[g[s]]);
//		F.resize(0), R.resize(0), G.resize(0);
//		memset(v, 0, sizeof(v));
//		memset(g, 0, sizeof(g));
//		e.clear();
//	}
//}

#include <stdio.h>
#include <memory.h>

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class ele{
public:
	int a, c;
};

vector <int> F[500003], R[500003], G[500003];

bool v[500003];
int stk[500003], stp;
void DFN(int c){
	v[c] = true;
	for (int i = 0; i < F[c].size(); i++){
		int n = F[c][i];
		if (!v[n])DFN(n);
	}
	stk[++stp] = c;
}
int mny[500003];
int g[500003], gtp, cst[500003];
void CYC(int c){
	g[c] = gtp;
	cst[gtp] += mny[c];
	for (int i = 0; i < R[c].size(); i++){
		int n = R[c][i];
		if (!g[n])CYC(n);
	}
}
int dp[500003];
bool e[500003];

int dy(int c){
	if (dp[c] != -1)return dp[c];

	if (e[c])dp[c] = 0; // end point
	else
		dp[c] = -4001; // not end point but can't go anywhere

	for (int i = 0; i < G[c].size(); i++){
		if (dy(G[c][i]) < 0)continue;
		dp[c] = max(dp[c], dy(G[c][i]) + cst[G[c][i]]);
	}

	return dp[c];
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		//F.resize(n + 1), R.resize(n + 1);
		for (int i = 1; i <= m; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			F[a].push_back(b);
			R[b].push_back(a);
		}

		stp = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", &mny[i]);
			if (!v[i])DFN(i);
		}

		gtp = 0;
		for (int i = stp; i >= 1; i--){
			if (!g[stk[i]]){
				gtp++;
				cst[gtp] = 0;
				CYC(stk[i]);
			}
		}

		for (int i = 1; i <= n; i++){
			for (int j = 0; j < F[i].size(); j++){
				int k = F[i][j];
				if (g[i] != g[k]){
					G[g[i]].push_back(g[k]);
				}
			}
		}
		for (int i = 1; i <= gtp; i++){
			sort(G[i].begin(), G[i].end());
			//G[i].resize(distance(G[i].begin(), unique(G[i].begin(), G[i].end())));
			G[i].resize(unique(G[i].begin(), G[i].end())-G[i].begin());
		}

		int s, p;
		scanf("%d %d", &s, &p);

		for (int i = 1; i <= p; i++){
			int a;
			scanf("%d", &a);
			e[g[a]] = true;
		}

		memset(dp, 0xff, sizeof(dp));
		printf("%d\n", dy(g[s]) + cst[g[s]]);
		//G.resize(0), R.resize(0), F.resize(0); // very slowly!!!
		for (int i = 1; i <= n; i++)F[i].clear(), R[i].clear();
		for (int i = 1; i <= gtp; i++)G[i].clear();
		memset(v, 0, sizeof(v));
		memset(g, 0, sizeof(g));
		memset(e, 0, sizeof(e));
	}
}