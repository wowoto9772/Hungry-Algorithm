#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int t[4];
int c[4][4];
int s[100003][4];

int tot[4];

int main() {

	int n;
	scanf("%d", &n);

	int k = 3;

	for (int i = 1; i <= k; i++)t[i] = i;

	for (int i = 1; i <= n; i++) {
		int o;
		scanf("%d", &o);

		tot[o]++;

		for (int j = 1; j <= k; j++) {
			s[i][j] = s[i - 1][j] + (o == j);
		}
	}

	int ans = n;

	int ch = 6;

	while (ch--) {

		int l = 0, r = 0;

		for (int i = 1; i <= k; i++) {
			l = r + 1;
			r += tot[t[i]];
			for (int j = 1; j <= k; j++) {
				c[j][t[i]] = s[r][j] - s[l - 1][j];
			}
		}

		int _2ex = 0, _3ex = 0;

		for (int i = 1; i < k; i++) {
			for (int j = i + 1; j <= k; j++) {
				int cur = min(c[i][j], c[j][i]);
				_2ex += cur;
				c[i][j] -= cur;
				c[j][i] -= cur;
			}
		}

		for (int i = 1; i < k; i++) {
			for (int j = i + 1; j <= k; j++) {
				_3ex += c[i][j] + c[j][i];
			}
		}

		_3ex = _3ex * 2 / 3;

		ans = min(ans, _2ex + _3ex);

		next_permutation(t + 1, t + 1 + 3);
	}

	printf("%d\n", ans);

}