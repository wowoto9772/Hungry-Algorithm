#include <stdio.h>

#include <vector>

#include <algorithm>

using namespace std;

int e[10003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		int tot = 0;

		for (int i = 1; i <= n; i++) {
			scanf("%d", &e[i]);

			tot += e[i];

		}

		vector <int> d;

		for (int i = 1; i*i <= tot; i++) {

			if (tot%i)continue;

			d.push_back(i);
			d.push_back(tot / i);

		}

		sort(d.begin(), d.end());

		for (int i = 0; i < d.size(); i++) {

			int lim = d[i];
			int m = 0;

			bool pos = true;

			for (int j = 1; pos && j <= n; j++) {

				m += e[j];

				if (lim == m) {

					m = 0;

				}
				else if (lim < m) {

					pos = false;

				}

			}

			if (pos) {
				printf("%d\n", d[i]);
				break;
			}

		}

	}

}