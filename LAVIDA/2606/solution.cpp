//#include <stdio.h>
//#include <queue>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//#define MAX 1000000007
//
//class ele{
//public:
//	short c;
//	int d, dl, dh;
//};
//
//class dat{
//public:
//	int a, c;
//};
//int A(int a){ return a < -a ? -a : a; }
//int m(int a, int b){ return a < b ? a : b; }
//int M(int a, int b){ return a < b ? b : a; }
//
//int main()
//{
//	freopen("D.in", "r", stdin);
//
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//
//		ele X[103];
//		int h[103]; // node's height
//
//		int n, e;
//		scanf("%d %d", &n, &e);
//
//		for (int i = 1; i <= n; i++){
//			scanf("%d", &h[i]);
//			X[i].d = MAX, X[i].dl = MAX, X[i].dh = -1;
//		}
//
//		vector <dat> lnk[103];
//
//		for (int i = 1; i <= e; i++){ // bidirectional (two-way)
//			int a, b, c;
//			dat ad;
//			scanf("%d %d %d", &a, &b, &ad.c);
//			ad.a = b;
//			lnk[a].push_back(ad);
//			ad.a = a;
//			lnk[b].push_back(ad);
//		}
//
//		queue <ele> q;
//		ele psh, pop;
//		X[1].c = 1, X[1].d = 0, X[1].dl = X[1].dh = h[1];
//		psh = X[1];
//		q.push(psh);
//
//		map < int, map <int, bool > > chk;
//
//		while (!q.empty()){
//			pop = q.front(); q.pop();
//			for (int i = 0; i < lnk[pop.c].size(); i++){
//				dat nxt = lnk[pop.c][i];
//				int cur = A(X[nxt.a].dh - X[nxt.a].dl);
//				psh.c = nxt.a;
//				psh.dl = m(pop.dl, h[nxt.a]);
//				psh.dh = M(pop.dh, h[nxt.a]);
//				psh.d = pop.d + nxt.c;
//				int ncur = A(psh.dh - psh.dl);
//				if (ncur < cur){
//					X[nxt.a] = psh;
//					q.push(psh);
//				}
//				else if (ncur == cur){
//					if (psh.d < X[nxt.a].d){
//						X[nxt.a] = psh;
//						q.push(psh);
//					}
//				}
//				else{
//					if (psh.dh <= h[n] && psh.d < X[nxt.a].d){
//						if (!chk[psh.c][psh.d])
//						{
//							chk[psh.c][psh.d] = true;
//							q.push(psh);
//						}
//					}
//				}
//			}
//		}
//
//		printf("%d %d\n", X[n].dh - X[n].dl, X[n].d);
//	}
//}
//
//#include <stdio.h>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//#define MAX 1000000007
//
//class ele{
//public:
//	int c, d, dl, dh;
//};
//
//class dat{
//public:
//	int a, c;
//};
//int A(int a){ return a < -a ? -a : a; }
//int m(int a, int b){ return a < b ? a : b; }
//int M(int a, int b){ return a < b ? b : a; }
//
//int main()
//{
//	freopen("D.in", "r", stdin);
//
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//
//		ele X[103];
//		int h[103]; // node's height
//
//		int n, e;
//		scanf("%d %d", &n, &e);
//
//		for (int i = 1; i <= n; i++){
//			scanf("%d", &h[i]);
//		}
//
//		vector <dat> lnk[103];
//
//		for (int i = 1; i <= e; i++){ // bidirectional (two-way)
//			int a, b, c;
//			dat ad;
//			scanf("%d %d %d", &a, &b, &ad.c);
//			ad.a = b;
//			lnk[a].push_back(ad);
//			ad.a = a;
//			lnk[b].push_back(ad);
//		}
//
//		int l = 0, r = MAX, dm;
//
//		int ansh = MAX, ansd = MAX;
//
//		while (l <= r){
//
//			dm = (l + r) / 2;
//
//			for (int i = 1; i <= n; i++){
//				X[i].d = MAX, X[i].dl = MAX, X[i].dh = -1;
//			}
//
//			queue <ele> q;
//			ele psh, pop;
//			X[1].c = 1, X[1].d = 0, X[1].dl = X[1].dh = h[1];
//			psh = X[1];
//			q.push(psh);
//
//			while (!q.empty()){
//				pop = q.front(); q.pop();
//				for (int i = 0; i < lnk[pop.c].size(); i++){
//					dat nxt = lnk[pop.c][i];
//					int cur = A(X[nxt.a].dh - X[nxt.a].dl);
//					psh.c = nxt.a;
//					psh.dl = m(pop.dl, h[nxt.a]);
//					psh.dh = M(pop.dh, h[nxt.a]);
//					psh.d = pop.d + nxt.c;
//
//					if (h[nxt.a] > dm)continue;
//
//					int ncur = A(psh.dh - psh.dl);
//					if (ncur < cur){
//						X[nxt.a] = psh;
//						q.push(psh);
//					}
//					else if (ncur == cur){
//						if (psh.d < X[nxt.a].d){
//							X[nxt.a] = psh;
//							q.push(psh);
//						}
//					}
//				}
//			}
//
//			int tmph = A(X[n].dh - X[n].dl);
//			if (ansh > tmph){
//				ansh = tmph;
//				ansd = X[n].d;
//				r = dm - 1;
//			}
//			else if (ansh == tmph){
//				ansd = m(ansd, X[n].d);
//				l = dm + 1;
//			}
//			else{
//				l = dm + 1;
//			}
//		}
//
//		printf("%d %d\n", ansh, ansd);
//	}
//}

//#include <stdio.h>
//#include <queue>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//#define MAX 1000000007
//
//class ele{
//public:
//	short c;
//	int d, dl, dh;
//};
//
//class dat{
//public:
//	int a, c;
//};
//int A(int a){ return a < -a ? -a : a; }
//int m(int a, int b){ return a < b ? a : b; }
//int M(int a, int b){ return a < b ? b : a; }
//
//int main()
//{
//	freopen("D.in", "r", stdin);
//
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//
//		ele X[103];
//		int h[103]; // node's height
//
//		int n, e;
//		scanf("%d %d", &n, &e);
//
//		for (int i = 1; i <= n; i++){
//			scanf("%d", &h[i]);
//		}
//
//		vector <dat> lnk[103];
//
//		for (int i = 1; i <= e; i++){ // bidirectional (two-way)
//			int a, b, c;
//			dat ad;
//			scanf("%d %d %d", &a, &b, &ad.c);
//			ad.a = b;
//			lnk[a].push_back(ad);
//			ad.a = a;
//			lnk[b].push_back(ad);
//		}
//
//		int l = 0, r = MAX, dh;
//
//		int ansh = MAX, ansd = MAX;
//
//		while (l <= r){
//
//			dh = (l + r) / 2;
//
//			for (int i = 1; i <= n; i++){
//				X[i].d = MAX, X[i].dl = MAX, X[i].dh = -1;
//			}
//
//			queue <ele> q;
//			ele psh, pop;
//			X[1].c = 1, X[1].d = 0, X[1].dl = X[1].dh = h[1];
//			psh = X[1];
//			q.push(psh);
//
//			while (!q.empty()){
//				pop = q.front(); q.pop();
//				for (int i = 0; i < lnk[pop.c].size(); i++){
//					dat nxt = lnk[pop.c][i];
//					int cur = A(X[nxt.a].dh - X[nxt.a].dl);
//					psh.c = nxt.a;
//					psh.dl = m(pop.dl, h[nxt.a]);
//					psh.dh = M(pop.dh, h[nxt.a]);
//					psh.d = pop.d + nxt.c;
//					int ncur = A(psh.dh - psh.dl);
//
//					if (ncur > dh)continue;
//
//					if (psh.d < X[nxt.a].d){
//						X[nxt.a] = psh;
//						q.push(psh);
//					}
//				}
//			}
//
//			if (X[n].d >= MAX){
//				l = dh + 1;
//			}
//			else{
//				r = dh - 1;
//				if (ansh > dh){
//					ansh = dh;
//					ansd = X[n].d;
//				}
//			}
//		}
//
//		printf("%d %d\n", ansh, ansd);
//	}
//}

#include <stdio.h>
#include <memory.h>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000000007

class dat{
public:
	int a, c;
};
int m(int a, int b){ return a < b ? a : b; }
int M(int a, int b){ return a < b ? b : a; }

int h[103]; // node's height

int n;
int d[103];
vector < dat > lnk[103];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){

		int e;
		scanf("%d %d", &n, &e);

		vector <int> x;
		for (int i = 1; i <= n; i++){
			scanf("%d", &h[i]);
			x.push_back(h[i]);
			lnk[i].clear();
		}

		for (int i = 1; i <= e; i++){ // bidirectional (two-way)
			int a, b, c;
			dat ad;
			scanf("%d %d %d", &a, &b, &ad.c);
			ad.a = b;
			lnk[a].push_back(ad);
			ad.a = a;
			lnk[b].push_back(ad);
		}
		
		sort(x.begin(), x.end());
		x.resize(distance(x.begin(), unique(x.begin(), x.end())));			
		int l = 0, r = MAX;
		int ansd, ansh;
		while (l <= r){
			int pans = (l + r) / 2;
			
			bool flag = false;
			for (int i = 0; i < x.size(); i++){
				if (x[i] <= h[1] && h[1] <= x[i] + pans){
					memset(d, 0x4f, sizeof(d));
					d[1] = 0;


					int hm = x[i];
					int hM = x[i] + pans;
					queue <int> q, c;
					q.push(1), c.push(0);;
					while (!q.empty()){
						int cur = q.front(); q.pop();
						int cst = c.front(); c.pop();
						for (int i = 0; i < lnk[cur].size(); i++){
							dat nxt = lnk[cur][i];
							if (hm > h[nxt.a])continue;
							if (hM < h[nxt.a])continue;
							int ncst = cst + nxt.c;
							if (d[nxt.a] > ncst){
								d[nxt.a] = ncst;
								if (nxt.a != n){
									q.push(nxt.a);
									c.push(ncst);
								}
							}
						}
					}
					if (d[n] < MAX){
						ansd = d[n], ansh = pans;
						r = pans - 1;
						flag = true;
						break;
					}
				}
			}
			if(!flag){
				l = pans + 1;
			}
		}

		printf("%d %d\n", ansh, ansd);
	}
}