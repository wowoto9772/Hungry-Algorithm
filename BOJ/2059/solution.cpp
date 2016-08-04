#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector < vector <int> > lnk;

vector < vector <int> > out;
bool vst[1003];

int id;
int top = 0;

void dfs(int c) {

	if (vst[c])return;

	vst[c] = true;

	for (int j = 0; j < lnk[c].size(); j++) {
		dfs(lnk[c][j]);
	}

	out[id].push_back(c);

}

int main() {

	int n;
	scanf("%d", &n);

	lnk.resize(n + 1);

	vector < int > p (n+1);

	for (int i = 1; i <= n; i++)p[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			int a;
			scanf("%d", &a);

			if (a) {

				lnk[j].push_back(i);

				int a = i, b = j;

				while (p[a] != a)a = p[a];
				while (p[b] != b)b = p[b];

				if (a != b)p[a] = b;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int a = i;
		while (p[a] != a)a = p[a];
		p[i] = a;
	}

	int c = 0;

	for (int i = 1; i <= n; i++) {

		if (i == p[i]) {

			c++;

		}

	}

	printf("%d\n", c);

	int cc = c;

	out.resize(c);

	for (int i = 1; i <= n && c; i++) {

		if (i == p[i]) {

			id = --c;

			for (int j = 1; j <= n; j++) {
				if(p[j] == i)dfs(j);
			}

		}
	}

	c = cc;

	for (int i = 0; i < c; i++) {

		printf("%d ", out[i].size());

		for (int j = 0; j < out[i].size(); j++)printf("%d ", out[i][j]);

		printf("\n");
	}

}