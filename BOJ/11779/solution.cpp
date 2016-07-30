#include <stdio.h>
#include <limits.h>

#include <vector>
#include <queue>

using namespace std;

class ele{
public:

	ele(){}

	ele(int a_, int c_){
		a = a_, c = c_;
	}

	int a, c;
	bool operator<(const ele &A)const{
		return c > A.c;
	}

};

int d[1003];
int r[1003];

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	vector < vector < ele > > lnk;

	lnk.resize(n + 1);

	for (int i = 1; i <= m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		lnk[a].emplace_back(b, c);
	}

	priority_queue <ele> q;

	int s, a;
	scanf("%d %d", &s, &a);

	for (int i = 1; i <= n; i++)d[i] = INT_MAX;

	d[s] = 0;
	q.emplace(s, 0);

	while (!q.empty()){
		ele pp = q.top(); q.pop();

		for (int i = 0; i < lnk[pp.a].size(); i++){
			ele psh = lnk[pp.a][i];

			if (d[psh.a] > pp.c + psh.c){
				psh.c += pp.c;
				d[psh.a] = psh.c;
				r[psh.a] = pp.a;
				q.emplace(psh);
			}
		}
	}

	printf("%d\n", d[a]);

	vector <int> ans;

	int src = a;
	while (src){
		ans.push_back(src);
		src = r[src];
	}

	printf("%d\n", ans.size());

	for (int i = ans.size() - 1; i >= 0; i--)printf("%d ", ans[i]);

}