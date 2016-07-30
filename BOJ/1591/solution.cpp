#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector < vector <int> > lnk;
map < int, map<int, int> > cap;
int in[1003];

vector <int> tmp;

void seq(int c) {

	for (int i = 0; i < lnk[c].size(); i++) {
		int n = lnk[c][i];
		if (cap[c][n] > 0) {
			cap[c][n]--;
//			if (c != n) {
//				cap[n][c]--;
//			}
			seq(n);
		}
	}

	tmp.push_back(c);
}

int main() {

	map < vector <int>, int > mp;
	map < int, vector <int> > dmp;

	int n, m;
	scanf("%d %d", &n, &m);

	lnk.resize(n + 1);

	int tp = 0;

	for (int i = 1; i <= n - m + 1; i++) {

		vector <int> p;

		for (int i = 1; i < m; i++) {

			int a;
			scanf("%d", &a);

			p.push_back(a);

		}

		if (!mp[p]) {
			mp[p] = ++tp;
			dmp[tp] = p;
		}

		int x = mp[p];

		int k;
		scanf("%d", &k);

		vector <int> q = p;
		q.erase(q.begin());
		q.push_back(k);

		if (!mp[q]) {
			mp[q] = ++tp;
			dmp[tp] = q;
		}

		int y = mp[q];

		if (!cap[x][y]) {
			lnk[x].push_back(y);
			cap[x][y] = 1;
		}
		else {
			cap[x][y]++;
		}

		in[y]++;

	}

	for (int i = 1; i <= tp; i++) {
		if (!in[i]) {
			seq(i);
			reverse(tmp.begin(), tmp.end());

			vector <int> ans;

			ans = dmp[tmp[0]];

			for (int i = 1; i < tmp.size(); i++) {
				ans.push_back(dmp[tmp[i]].back());
			}

			for (int i = 0; i < ans.size(); i++)printf("%d ", ans[i]);
			return 0;
		}
	}

	// 여기도 온다...
	while (true) {}

}

/*
	4 3
	1 2 4
	2 4 3

	4 2
	2 2
	2 2
	2 2

	4 2
	2 4
	4 2
	2 2

	5 4
	1 2 3 4
	4 1 2 3
*/