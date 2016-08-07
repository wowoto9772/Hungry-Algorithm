#include <stdio.h>

#include <set>
#include <vector>

#include <algorithm>

using namespace std;

vector < int > seq[23];

int cc[1 << 22];

void make_all() {

	for (int i = 1; i < (1 << 22); i++) {

		int c = 0, m = 0;

		for (int j = 0; j < 22; j++) {
			if (i&(1 << j)) {
				c += j + 1;
				m++;
			}
		}

		if (c <= 22)
		{
			seq[c].push_back(i);
		}
		cc[i] = m;

	}

}

int n, t;

int main() {

	make_all();

	int tc = 0;

	while (scanf("%d %d", &n, &t) == 2) {

		if (!(n | t))break;

		tc++;

		int ans = 0;

		set <int> dp;

		dp.insert(0);

		int cannot = 1 << n;

		int mm = 0;

		for (int i = 0; i < t; i++) {

			int e;
			scanf("%d", &e);

			set <int> ndp;

			for (auto &cur : dp) {

				for (int j = 0; j < seq[e].size(); j++) {

					int has = seq[e][j];

					if (cur & has)continue;

					if (has >= cannot)break;

					int added = cur | has;

					ndp.insert(added);

					ans = max(ans, cc[added]);

				}

			}

			dp = ndp;

		}

		printf("Game %d: %d\n", tc, ans);

	}

}