#include <stdio.h>
#include <memory.h>

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class ele{
public:
	int a, c;
	bool operator<(const ele &A)const{
		return c > A.c;
	}
};

int d[10003];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		priority_queue <ele> Q;
		ele psh, pop;

		vector < vector < ele > > L;
		L.resize(n);

		for (int i = 1; i <= m; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);

			psh.a = b, psh.c = c;
			L[a].push_back(psh);

			psh.a = a;
			L[b].push_back(psh);
		}

		//for (int i = 0; i < n; i++)sort(L[i].begin(), L[i].end());

		psh.a = 0, psh.c = 0;
		Q.push(psh);

		bool chk[10003] = { 0 };
		memset(d, 0x4f, sizeof(d));

		while (!Q.empty()){
			pop = Q.top();
			Q.pop();

			if (chk[pop.a])continue;
			chk[pop.a] = true;

			for (int i = 0; i < L[pop.a].size(); i++){
				psh = L[pop.a][i];
				if (!chk[psh.a] && d[psh.a] > pop.c + psh.c){
					d[psh.a] = pop.c + psh.c;
					psh.c = d[psh.a];
					Q.push(psh);
				}
			}
		}

		printf("%d\n", d[n - 1]);
	}
}