#include <stdio.h>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

class BIT{
public:

	vector <ll> T;
	int S;

	BIT(const int n){
		S = n;
		T.resize(S + 1);
	}

	void Update(int p, int v){

		while (p <= S){
			T[p] += v;
			p += p & (-p);
		}

	}

	ll Sum(int p){

		ll ret = 0;
		while (p > 0){
			ret += T[p];
			p -= p & (-p);
		}return ret;

	}
};

int p[500003];

vector < vector <int> > lnk;

int le[500003], ri[500003];
int level;

void dfs(int c) {

	le[c] = ++level;

	for (int i = 0; i < lnk[c].size(); i++) {
		dfs(lnk[c][i]);
	}

	ri[c] = level;
	
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	scanf("%d", &p[1]);

	lnk.resize(n + 1);

	for (int i = 2; i <= n; i++) {

		int my;
		scanf("%d %d", &p[i], &my);

		lnk[my].push_back(i);

	}

	dfs(1);

	BIT tree(n);

	for (int i = 1; i <= m; i++) {

		char cmd;
		scanf(" %c", &cmd);

		int v;
		scanf("%d", &v);

		if (cmd == 'p') {

			int c;
			scanf("%d", &c);

			// add v's descendents's pay
			tree.Update(le[v], c);
			tree.Update(ri[v], -c);

			// only update le[v] to ri[v] - 1

			// ri[v] : v's next_node level

		}
		else {

			// print pay

			printf("%lld\n", p[v] + tree.Sum(le[v] - 1));

		}

	}

}