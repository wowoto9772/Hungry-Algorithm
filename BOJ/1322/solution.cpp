#include <stdio.h>
#include <limits.h>

#include <vector>

#define ll long long

using namespace std;

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	vector <int> s;

	for (ll i = 0; (1LL << i) <= LLONG_MAX / 2; i++) {
		if (!(n & 1)) {
			s.push_back(i);
		}
		n >>= 1;
	}

	int t = 0;

	ll ans = 0;

	while (k) {
		if (k & 1) {
			ans |= 1LL << s[t];
		}
		k >>= 1;
		t++;
	}

	printf("%lld\n", ans);

}