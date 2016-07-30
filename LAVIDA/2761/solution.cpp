#include <stdio.h>
#include <vector>

using namespace std;

#define fi (2*i-1)
#define se (2*i)

const int lim = 500;

int main() {

	int n;
	scanf("%d", &n);

	for (int b = 1; b*b <= n; b++) {

		int a = b;

		if (a + 1 + 2 * b <= lim) {

			int cnt = a*b + b*(b - 1);

			// (2)(1)(x), (1)(1)(2x)

			if (cnt <= n) {

				int k = n - cnt;

				int tot = a + 1 + 2 * b + k;

				if (tot <= lim) {

					vector < vector <int> > lnk;
					lnk.resize(tot + 1);

					for (int i = 1; i <= a; i++)lnk[i].push_back(a + 1);

					int mid = a + 1;

					for (int i = 1; i <= b; i++) {
						lnk[mid].push_back(mid + fi);
						lnk[mid + fi].push_back(mid + se);
					}

					int ri = mid + 2 * b;

					for (int i = 0; i < k; i++) {
						lnk[ri + i].push_back(ri + i + 1);
					}

					printf("%d\n", tot);

					int x = 0;

					for (int i = 1; i <= tot; i++) {
						for (int j = 0; j < lnk[i].size(); j++) {
							printf("%d %d\n", i, lnk[i][j]);
							x++;
						}
					}

					if (x == tot - 1)return 0;
					else
						while (true) {}

				}

			}

		}
	}

	while (true) {}

}