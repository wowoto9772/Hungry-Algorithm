#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {

		ll a[3];
		for (int i = 0; i < 3; i++)scanf("%lld", &a[i]);

		sort(a, a + 3);

		a[0] += a[1];

		printf("%lld\n", a[0] * a[0] + a[2] * a[2]);
	}
}