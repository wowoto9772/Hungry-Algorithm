#include <stdio.h>
#include <functional>
#include <string.h>
#include <queue>
#include <algorithm>

#define ll long long

using namespace std;

char str[15];
ll sum['J' + 3];
bool notz['J' + 3];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%s", str);

		int s = strlen(str);
		ll d = 1;

		notz[str[0]] = true;

		for (int j = s - 1; j >= 0; j--) {
			sum[str[j]] += d;
			d *= 10LL;
		}
	}

	ll ans = 0;
	int a[13] = { 0 };
	int top = 0;

	for (int i = 'A'; i <= 'J'; i++) {
		if (sum[i]) {
			a[top++] = i;
		}
	}

	while (true) {
		if (!notz[a[top - 1]] || notz[a[top-1]] && top != 10) {
			ll tmp = 0;
			ll d = 9;
			for (int i = 0; i < top; i++) {
				tmp += sum[a[i]] * d--;
			}
			ans = max(ans, tmp);
		}
		if (!next_permutation(a, a + top))break;
	}

	printf("%lld\n", ans);

}