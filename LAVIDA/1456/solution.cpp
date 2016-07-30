#include <stdio.h>
#include <memory.h>

#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class ele{
public:
	int a, c, d;
	bool operator<(const ele &A)const{
		return c < A.c;
	}
};

int main(){
	int n, m;
	while (scanf("%d %d", &n, &m) == 2){
		vector < vector < ele > > L;
		ele psh, pop;

		L.resize(n);

		for (int i = 0; i < m; i++){
			int a[4] = { 0 };
			for (int j = 0; j < 4; j++)scanf("%d", &a[j]);
			psh.a = a[1], psh.d = a[2], psh.c = a[3];
			L[a[0]].push_back(psh);
			psh.a = a[0];
			L[a[1]].push_back(psh);
		}

		for (int i = 0; i < n; i++)sort(L[i].begin(), L[i].end());

		int s, a, p;
		scanf("%d %d %d", &s, &a, &p);

		queue <ele> Q;
		psh.a = s, psh.c = psh.d = 0;
		Q.push(psh);

		int d[103], c[103];
		memset(d, 0x2f, sizeof(d));
		memset(c, 0x2f, sizeof(c));
		d[s] = c[s] = 0;

		while (!Q.empty()){
			pop = Q.front();
			Q.pop();

			for (int i = 0; i < L[pop.a].size(); i++){
				psh = L[pop.a][i];
				if (d[psh.a] > pop.d + psh.d && pop.c + psh.c <= p){
					d[psh.a] = pop.d + psh.d;
					c[psh.a] = pop.c + psh.c;
					psh.c = c[psh.a], psh.d = d[psh.a];
					Q.push(psh);
				}
			}
		}

		printf("%d\n", d[a]);
	}
}