#include <stdio.h>
#include <memory.h>

#include <vector>
#include <queue>

using namespace std;

class dat{
public:
	int a, c;
};

int d[1003];

int main()
{
	int n, m;
	scanf("%d %d", &m, &n);

	vector < dat > L[1002];

	dat psh, pop;

	for (int i = 1; i <= m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		psh.a = b, psh.c = c;
		L[a].push_back(psh);
		psh.a = a;
		L[b].push_back(psh);
	}

	memset(d, 0x4f, sizeof(d));

	queue <dat> Q;
	psh.a = 1, psh.c = 0;
	d[1] = 0;
	Q.push(psh);

	while (!Q.empty()){
		pop = Q.front(); Q.pop();

		for (int i = 0; i < L[pop.a].size(); i++){
			psh = L[pop.a][i];
			if (d[psh.a] > pop.c + psh.c){
				d[psh.a] = pop.c + psh.c;
				psh.c = d[psh.a];
				Q.push(psh);
			}
		}
	}

	printf("%d\n", d[n]);
}