//#include <stdio.h>
//#include <iostream>
//#include <memory.h>
//#include <map>
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int top = 1;
//bool chk[210];
//int pcst[210];
//bool id[210][210];
//
//class ele{
//public:
//	int a, c;
//};
//
//int main()
//{
//	int n, m, q;
//	scanf("%d %d %d", &n, &m, &q);
//
//	map <string, int> wh;
//
//	vector < vector <ele> > L;
//	L.resize(n * 15 + 3);
//
//	ele psh, pop;
//
//	for (int i = 1; i <= n; i++){
//		int c;
//		scanf("%d", &c);
//		string I[18];
//		for (int j = 1; j <= c; j++){
//			cin >> I[j];
//			int cost;
//			if (j < c)scanf("%d", &cost);
//			if (wh[I[j]] == 0){
//				wh[I[j]] = top++;
//				id[i][wh[I[j]]] = true;
//			}
//			else{
//
//			}
//			if (j >= 2){
//				psh.a = wh[I[j]];
//				psh.c = cost;
//				L[wh[I[j - 1]]].push_back(psh);
//				psh.a = wh[I[j - 1]];
//				L[wh[I[j]]].push_back(psh);
//			}
//		}
//	}
//
//	for (int i = 1; i <= m; i++){
//		string x;
//		cin >> x;
//		chk[wh[x]] = true;
//		scanf("%d", &pcst[wh[x]]);
//	}
//
//	for (int i = 1; i <= q; i++){
//		string xi, xj;
//		cin >> xi >> xj;
//		int s = wh[xi], a = wh[xj];
//
//		queue <ele> Q;
//		psh.a = s, psh.c = 0;
//		Q.push(psh);
//
//		int d[210];
//		memset(d, 0x2f, sizeof(d));
//		d[s] = 0;
//
//		while (!Q.empty()){
//			pop = Q.front(); Q.pop();
//
//			for (int i = 0; i < L[pop.a].size(); i++){
//				psh = L[pop.a][i];
//				int nec = pop.c + psh.c;
//				bool f = false;
//				for (int x = 1; !f && x <= n; x++){
//					if (id[x][psh.a] && id[x][pop.a]){
//						f = true;
//					}
//				}
//				if (!f){
//					if (chk[psh.a] && chk[pop.a])nec += pcst[psh.a];
//					else if (chk[psh.a])nec += pcst[psh.a];
//					else if (chk[pop.a])nec += pcst[pop.a];
//				}
//				if (d[psh.a] > nec){
//					d[psh.a] = nec;
//					psh.c = d[psh.a];
//					Q.push(psh);
//				}
//			}
//		}
//
//		printf("%d\n", d[a]);
//	}
//}

//#include <stdio.h>
//#include <limits.h>
//#include <memory.h>
//
//#include <iostream>
//#include <map>
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int top = 0;
//class ele{
//public:
//	int a, c;
//};
//
//int mm(int a, int b){ return a < b ? a : b; }
//
//int main()
//{
//	int n, m, q;
//	scanf("%d %d %d", &n, &m, &q);
//
//	map <int, string> wh;
//
//	vector < vector <ele> > L;
//
//	L.resize(n * 15 + 3);
//
//	ele psh, pop;
//
//	for (int i = 1; i <= n; i++){
//		int c;
//		scanf("%d", &c);
//		string I[18];
//		for (int j = 1; j <= c; j++){
//			int cst;
//			if (j > 1){
//				scanf("%d", &cst);
//				psh.a = top;
//				psh.c = cst;
//				L[top - 1].push_back(psh);
//				psh.a = top - 1;
//				L[top].push_back(psh);
//			}
//			cin >> I[j];
//			wh[top] = I[j];
//			top++;
//		}
//	}
//
//	map <string, int> ex;
//
//	for (int i = 1; i <= m; i++){
//		string x;
//		cin >> x;
//		int cst;
//		scanf("%d", &cst);
//
//		ex[x] = cst;
//	}
//
//	for (int i = 1; i <= q; i++){
//		string xi, xj;
//		cin >> xi >> xj;
//
//		vector <int> S, A;
//
//		int ans = INT_MAX;
//
//		for (int j = 0; j < top; j++){
//			if (wh[j] == xi)S.push_back(j);
//			if (wh[j] == xj)A.push_back(j);
//		}
//
//		for (int j = 0; j < S.size(); j++){
//			queue <ele> Q;
//			psh.a = S[j], psh.c = 0;
//			Q.push(psh);
//
//			int d[210];
//			memset(d, 0x2f, sizeof(d));
//			d[S[j]] = 0;
//
//			while (!Q.empty()){
//				pop = Q.front(); Q.pop();
//				for (int i = 0; i < L[pop.a].size(); i++){
//					psh = L[pop.a][i];
//					int nec = pop.c + psh.c;
//					if (d[psh.a] > nec){
//						d[psh.a] = nec;
//						psh.c = d[psh.a];
//						Q.push(psh);
//					}
//				}
//				if (ex[wh[pop.a]] > 0){
//					for (int j = 0; j < top; j++){
//						if (pop.a != j){
//							if (wh[j] == wh[pop.a]){
//								if (d[j] > pop.c + ex[wh[pop.a]]){
//									d[j] = pop.c + ex[wh[pop.a]];
//									psh.a = j;
//									psh.c = d[j];
//									Q.push(psh);
//								}
//							}
//						}
//					}
//				}
//			}
//
//			for (int k = 0; k < A.size(); k++){
//				ans = mm(ans, d[A[k]]);
//			}
//		}
//
//
//		printf("%d\n", ans);
//	}
//}

/*
3 2 5
4
sn 2 ga 2 ye 2 seol
2
ga 3 ya
3
seon 3 seol 2 ha
ga 3
seol 1
ye ye
ha ya
ga seol
sn ha
ya sn

3 5 3
5
gl 1 ke 3 kn 2 hy 3 gr
4
gl 3 ke 3 sl 1 vi
2 gr 5 vi
gr 3
vi 2
sl 2
ke 1
gl 2
hy sl
gr sl
gl vi
*/

#include <stdio.h>
#include <limits.h>
#include <memory.h>

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int top = 0;

int mm(int a, int b){ return a < b ? a : b; }

int f[210][210];

int main()
{
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);

	map <int, string> wh;

	memset(f, 0x2f, sizeof(f));

	for (int i = 1; i <= n; i++){
		int c;
		scanf("%d", &c);
		string I[18];
		for (int j = 1; j <= c; j++){
			f[top][top] = 0;
			int cst;
			if (j > 1){
				scanf("%d", &cst);
				f[top - 1][top] = cst;
				f[top][top - 1] = cst;
			}
			cin >> I[j];
			wh[top] = I[j];
			top++;
		}
	}

	for (int i = 1; i <= m; i++){
		string x;
		cin >> x;
		int cst;
		scanf("%d", &cst);

		vector <int> W;
		for (int j = 0; j < top; j++){
			if (wh[j] == x){
				W.push_back(j);
			}
		}

		for (int j = 0; j < W.size(); j++){
			for (int k = 0; k < W.size(); k++){
				if (j != k)f[W[j]][W[k]] = cst;
			}
		}
	}

	for (int k = 0; k < top; k++){
		for (int i = 0; i < top; i++){
			for (int j = 0; j < top; j++){
				f[i][j] = mm(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}

	for (int i = 1; i <= q; i++){
		string xi, xj;
		cin >> xi >> xj;

		vector <int> S, A;

		for (int j = 0; j < top; j++){
			if (wh[j] == xi)S.push_back(j);
			if (wh[j] == xj)A.push_back(j);
		}

		int ans = INT_MAX;

		for (int j = 0; j < S.size(); j++){
			for (int k = 0; k < A.size(); k++){
				ans = mm(ans, f[S[j]][A[k]]);
			}
		}

		printf("%d\n", ans);
	}
}