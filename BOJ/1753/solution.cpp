#include <stdio.h>
#include <limits.h>

#include <vector>
#include <queue>

using namespace std;

class ele{
public:
	int a, c;
};

int d[20003];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int s;
	scanf("%d", &s);

	vector < vector <ele> > L;
	ele psh, pop;

	L.resize(n + 1);

	for (int i = 1; i <= m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		psh.a = b, psh.c = c;
		L[a].push_back(psh);
	}

	for (int i = 1; i <= n; i++)d[i] = INT_MAX;
	d[s] = 0;

	queue <ele> X;
	psh.a = s, psh.c = 0;

	X.push(psh);

	while (!X.empty()){
		pop = X.front();
		X.pop();

		for (int i = 0; i < L[pop.a].size(); i++){
			psh = L[pop.a][i];
			if (d[psh.a] > pop.c + psh.c){
				d[psh.a] = pop.c + psh.c;
				psh.c = d[psh.a];
				X.push(psh);
			}
		}
	}

	for (int i = 1; i <= n; i++){
		if (d[i] == INT_MAX)printf("INF\n");
		else
			printf("%d\n", d[i]);
	}
}