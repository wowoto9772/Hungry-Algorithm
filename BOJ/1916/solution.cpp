#include <stdio.h>
#include <limits.h>

#include <vector>
#include <queue>

using namespace std;

class ele{
public:
	int a, c;
	ele(){}
	ele(int a_, int c_){ a = a_, c = c_; }
};

int d[1003];

int main(){

	vector < vector <ele> > lnk;

	int n, m;
	scanf("%d %d", &n, &m);

	lnk.resize(n + 1);

	for (int i = 1; i <= m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		lnk[a].emplace_back(b, c);
	}

	int s, a;
	scanf("%d %d", &s, &a);

	for (int i = 1; i <= n; i++)d[i] = INT_MAX;

	queue <ele> q;
	q.emplace(s, a);

	d[s] = 0;

	while (!q.empty()){
		ele pp = q.front(); q.pop();
		for (int i = 0; i < lnk[pp.a].size(); i++){
			ele psh = lnk[pp.a][i];
			if (d[psh.a] > d[pp.a] + psh.c){
				d[psh.a] = d[pp.a] + psh.c;
				psh.c = d[psh.a];
				q.emplace(psh);
			}
		}
	}

	printf("%d\n", d[a]);
}