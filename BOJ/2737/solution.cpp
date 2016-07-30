#include <stdio.h>
#include <set>

using namespace std;

#define ll long long

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);


		// a + ... ~ + a+x-1
		// (2a + (x-1))*x/2 = n

		n <<= 1LL;

		set <int> v;

		for (ll i = 2; i*i <= n; i++) {

			if (n%i)continue;

			v.insert(i);
			v.insert(n / i);

		}

		int ans = 0;

		for (auto &d : v) {

			int k = n / d;
			// 2a+d-1 == k

			k += 1 - d;

			if (k <= 0)break;

			if (k & 1)continue;

			ans++;

		}

		printf("%d\n", ans);

	}

}