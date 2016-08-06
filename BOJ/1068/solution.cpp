#include <stdio.h>
#include <vector>

using namespace std;

bool removed[53];

vector < vector <int> > lnk;

int ans;

void dfs(int c) {

	if (removed[c])return;

	if (lnk[c].empty() || lnk[c].size() == 1 && removed[lnk[c][0]])ans++;
	else {

		for (int i = 0; i < lnk[c].size(); i++) {
			dfs(lnk[c][i]);
		}

	}

}

int main() {

	int n;
	scanf("%d", &n);

	lnk.resize(n);

	int root = -1;

	for (int i = 0; i < n; i++) {

		int k;
		scanf("%d", &k);

		if (k == -1)root = i;
		else {

			lnk[k].push_back(i);

		}

	}

	int r;
	scanf("%d", &r);

	removed[r] = true;

	dfs(root);

	printf("%d\n", ans);

}