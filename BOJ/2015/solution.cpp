#include <stdio.h>

#include <map>

using namespace std;

#define ll long long

int s[200003];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {

		int v;
		scanf("%d", &v);

		s[i] = s[i - 1] + v;

	}

	map <int, int> cnt;

	cnt[0] = 1;

	ll ans = 0;

	for (int i = 1; i <= n; i++) {

		ans += cnt[k - s[i]];

		// e[j] ~ e[i] = sum[i] - sum[j-1]

		cnt[-s[i]]++;

	}

	printf("%lld\n", ans);

}