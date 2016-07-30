#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

int I[100003];
ll S[100003];

int main()
{

	int n, m, w;
	scanf("%d %d %d", &n, &m, &w);

	for (int i = 1; i <= n; i++)scanf("%d", &I[i]);

	ll l = 1, r = 2000000000, x;
	ll ans = 0;

	while (l <= r) {
		x = (l + r) / 2;
		int c = 0;
		for (int i = 1; i <= n; i++) {
			int a = i - 1;
			int b = i - w;
			S[i] = S[i - 1];
			if (b < 0)b = 0;
			int k = S[a] - S[b];
			if (I[i] < x) {
				if (I[i] + k < x) {
					int cp = x - (I[i] + k);
					S[i] += cp;
					c += cp;
					if (c > m)break;
				}
			}
		}
		if (c > m)r = x - 1;
		else {
			l = x + 1;
			ans = max(ans, x);
		}
	}
	printf("%lld\n", ans);
}