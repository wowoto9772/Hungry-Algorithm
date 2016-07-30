#include <stdio.h>
#include <vector>

using namespace std;

#define ll long long
#define mod 1000000007LL

int right(int n) {
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		bool flag = false;
		int up = 0;

		for (int j = 0; !flag && j < n; j++) {
			if (i&(1 << j)) {
				up++;
			}
			else {
				up--;
				if (up < 0)flag = true;
			}
		}

		if (!flag && !up) {
			ans++;
			for (int j = 0; j < n; j++) {
				if (i&(1 << j))printf("(");
				else
					printf(")");
			}printf("\n");
		}
	}
	return ans;
} // 1 2 5 14 42 ... catalan number

/* find a pair (c,d) s.t. ac + bd = gcd(a,b)
 * Dependencies: none */
pair<long long, long long> extended_gcd(long long a, long long b) {
	if (b == 0) return make_pair(1, 0);
	pair<long long, long long> t = extended_gcd(b, a % b);
	return make_pair(t.second, t.first - t.second * (a / b));
}

/* Find x in [0,m) s.t. ax กี gcd(a, m) (mod m)
 * Dependencies: extended_gcd(a, b) */
long long modinverse(long long a, long long m) {
	return (extended_gcd(a, m).first % m + m) % m;
}


ll dp[2503];

int main() {

	dp[1] = 1;
	for (int i = 1; i < 2500; i++) {
		dp[i + 1] = 2LL * (2LL * i + 1LL) * dp[i];
		dp[i + 1] %= mod;
		dp[i + 1] *= modinverse((i + 2LL), mod);
		dp[i + 1] %= mod;
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		if (n % 2)printf("0\n");
		else {
			n /= 2;
			printf("%lld\n", dp[n]);
		}
	}

}