#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

const int h[] = { 100007, 1000003, 500009 };

int pwmd[26][200005][3]; // (i ^ j) % h[k]

char str[200003];

int n;

set < pair <int, int> > hsh[100007];

bool possible(int len) {

	for (int i = 0; i < 100007; i++)hsh[i].clear();

	int cur[] = { 0, 0, 0 };

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < len; i++) {
			cur[j] = (cur[j] * 26 + str[i]) % h[j];
		}
	}

	for (int i = len; i <= n; i++) {

		pair <int, int> cmpr = { cur[1], cur[2] };

		set < pair<int, int> > ::iterator it = hsh[cur[0]].lower_bound(cmpr);

		if (it != hsh[cur[0]].end() && *it == cmpr)return true;

		if (i == n)return false;

		hsh[cur[0]].emplace(cur[1], cur[2]);

		for (int j = 0; j < 3; j++) {

			cur[j] = (cur[j] * 26 + str[i]) % h[j];
			cur[j] = (cur[j] - pwmd[str[i - len]][len][j] + h[j]) % h[j];

		}

	}

	return false;

}

int main() {

	scanf("%d", &n);

	scanf("%s", str);

	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 26; i++) {
			pwmd[i][0][k] = i;
			for (int j = 1; j <= n; j++)pwmd[i][j][k] = (pwmd[i][j - 1][k] * 26) % h[k];
		}

	}

	for (int i = 0; i < n; i++) {
		str[i] = str[i] - 'a';
	}

	int l = 1, r = n - 1, m;

	int ans = 0;

	while (l <= r) {

		m = (l + r) / 2;

		if (possible(m)) {
			ans = max(ans, m);
			l = m + 1;
		}
		else {
			r = m - 1;
		}

	}

	printf("%d\n", ans);

}