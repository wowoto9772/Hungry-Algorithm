#include <stdio.h>
#include <memory.h>

#include <vector>
#include <queue>

using namespace std;

class ele{
public:
	int a, c;
};

int d[1003]; // s to x
int rd[1003]; // x to s

int main(){
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);

	vector < vector <ele> > lnk, rnk;

	lnk.resize(n + 1);
	rnk.resize(n + 1);

	ele psh, pop;

	for (int i = 1; i <= m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		psh.a = b, psh.c = c;
		lnk[a].push_back(psh);
		psh.a = a;
		rnk[b].push_back(psh);
	}

	queue <ele> q;
	psh.a = s, psh.c = 0;
	q.push(psh);
	memset(d, 0x4f, sizeof(d));

	d[s] = 0;

	while (!q.empty()){
		pop = q.front(); q.pop();
		for (int i = 0; i < lnk[pop.a].size(); i++){
			psh = lnk[pop.a][i];
			if (d[psh.a] > pop.c + psh.c){
				d[psh.a] = pop.c + psh.c;
				psh.c = d[psh.a];
				q.push(psh);
			}
		}
	}

	psh.a = s, psh.c = 0;
	q.push(psh);
	memset(rd, 0x4f, sizeof(rd));

	rd[s] = 0;

	while (!q.empty()){
		pop = q.front(); q.pop();
		for (int i = 0; i < rnk[pop.a].size(); i++){
			psh = rnk[pop.a][i];
			if (rd[psh.a] > pop.c + psh.c){
				rd[psh.a] = pop.c + psh.c;
				psh.c = rd[psh.a];
				q.push(psh);
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++){
		if (max < d[i] + rd[i]){
			max = d[i] + rd[i];
		}
	}

	printf("%d\n", max);
}