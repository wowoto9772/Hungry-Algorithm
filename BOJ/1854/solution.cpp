//#include <stdio.h>
//#include <limits.h>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class ele{
//public:
//	int a, c;
//	ele(){}
//	ele(int x, int y){
//		a = x, c = y;
//	}
//	bool operator<(const ele &A)const{
//		return c > A.c;
//	}
//};
//
//vector < vector <ele> > lnk; // edge
//
//int main(){
//	int n, m, k;
//	scanf("%d %d %d", &n, &m, &k);
//
//	lnk.resize(n + 1);
//
//	ele psh, pop;
//
//	for (int i = 1; i <= m; i++){
//		int a;
//		scanf("%d %d %d", &a, &psh.a, &psh.c);
//		lnk[a].push_back(psh);
//	}
//
//	vector < vector<int> > d;
//	d.resize(n + 1);
//	d[1].push_back(0);
//
//	priority_queue <ele> q;
//	q.emplace(1, 0);
//
//	while (!q.empty()){
//		ele pop = q.top(); q.pop();
//
//		if (d[pop.a].size() == k){
//			//if (d[pop.a][k - 1] > pop.c)continue;
//		}
//
//		for (int i = 0; i < lnk[pop.a].size(); i++){
//			ele psh = lnk[pop.a][i];
//			int cst = pop.c + psh.c;
//			if (d[psh.a].size() < k){
//				q.emplace(psh.a, cst);
//				d[psh.a].push_back(cst);
//				sort(d[psh.a].begin(), d[psh.a].end());
//			}
//			else{
//				if (d[psh.a][k - 1] < cst){
//					continue;
//				}
//				else if(d[psh.a][k-1] > cst){
//					d[psh.a][k - 1] = cst;
//					sort(d[psh.a].begin(), d[psh.a].end());
//					q.emplace(psh.a, cst);
//				}
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; i++){
//		sort(d[i].begin(), d[i].end());
//		if (d[i].size() < k)printf("-1\n");
//		else{
//			printf("%d\n", d[i][k-1]);
//		}
//	}
//}

#include <stdio.h>
#include <limits.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class ele{
public:
	int a, c;
	ele(){}
	ele(int x, int y){
		a = x, c = y;
	}
	bool operator<(const ele &A)const{
		return c > A.c;
	}
};

vector < vector <ele> > lnk; // edge

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	lnk.resize(n + 1);

	ele psh, pop;

	for (int i = 1; i <= m; i++){
		int a;
		scanf("%d %d %d", &a, &psh.a, &psh.c);
		lnk[a].push_back(psh);
	}


	priority_queue <ele> q;
	priority_queue <int> d[1003];
	d[1].push(0);

	q.emplace(1, 0);

	while (!q.empty()){
		ele pop = q.top(); q.pop();

		if (d[pop.a].size() == k){
			// if (d[pop.a].top() > pop.c)continue;
		}

		for (int i = 0; i < lnk[pop.a].size(); i++){
			ele psh = lnk[pop.a][i];
			int cst = pop.c + psh.c;
			if (d[psh.a].size() < k){
				q.emplace(psh.a, cst);
				d[psh.a].push(cst);
			}
			else{
				if (d[psh.a].top() <= cst){
					continue;
				}
				else{
					d[psh.a].pop();
					d[psh.a].push(cst);
					q.emplace(psh.a, cst);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++){
		if (d[i].size() < k)printf("-1\n");
		else{
			printf("%d\n", d[i].top());
		}
	}
}