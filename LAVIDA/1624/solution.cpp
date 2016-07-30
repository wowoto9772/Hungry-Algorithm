#include <stdio.h>
#include <memory.h>

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

vector < vector < ele > > L;

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		L.resize(0);
		L.resize(n + 1);

		ele psh, pop;

		for (int i = 1; i <= m; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			psh.a = b, psh.c = c;
			L[a].push_back(psh);
			psh.a = a;
			L[b].push_back(psh);
		}


		int d[1003], r[1003] = { 0 }; // r is argument path
		memset(d, 0x4f, sizeof(d));

		bool chk[1003] = { 0 };

		priority_queue <ele> Q;
		psh.a = 1, psh.c = 0;
		Q.push(psh);

		d[1] = 0;

		while (!Q.empty()){
			pop = Q.top();
			Q.pop();

			if (chk[pop.a])continue;
			chk[pop.a] = true;

			for (int i = 0; i < L[pop.a].size(); i++){
				psh = L[pop.a][i];
				if (!chk[psh.a]){
					int cst = pop.c + psh.c;
					if (d[psh.a] > cst){
						d[psh.a] = cst;
						r[psh.a] = pop.a;
						psh.c = cst;
						Q.push(psh);
					}
					else if (d[psh.a] == cst){
						int r1[1003] = { 0 }, r2[1003] = { 0 };
						int rt = 0, rt2 = 0;

						r1[rt] = r2[rt2] = psh.a;
						rt++, rt2++;

						int srh = r[psh.a];
						while (srh){ // previous
							r1[rt++] = srh;
							srh = r[srh];
						}

						srh = pop.a;
						while (srh){ // new
							r2[rt2++] = srh;
							srh = r[srh];
						}

						for (; rt >= 0 && rt2 >= 0; rt--, rt2--){
							if (r1[rt] > r2[rt2]){
								r[psh.a] = pop.a;
								break;
							}
							else if (r1[rt] == r2[rt2])continue;
							else{
								break;
							}
						}
					}
				}
			}
		}

		printf("%d\n", d[n]);
		
		int asrh = n;
		int ans[1003] = { 0 }, ant = 0;
		while (asrh){
			ans[ant++] = asrh;
			asrh = r[asrh];
		}

		for (int i = ant - 1; i > 0; i--)printf("%d ", ans[i]);
		printf("%d\n", ans[0]);
	}
}