#include <stdio.h>
#include <algorithm>

#define ll long long

using namespace std;

int a[100003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	ll ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (i - 2 >= 0) {
			ans += a[i] + a[i - 1];
			i -= 2;
		}
		else {
			ans += a[i];
		}
	}

	printf("%lld\n", ans);

}