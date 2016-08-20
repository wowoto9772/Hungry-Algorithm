
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	long long v;
	scanf("%lld", &v);

	if ((v & 1) == 0) { // 2mn
		v >>= 1;
		for (int m = 1; m*m <= v; m++) {
			if (v%m)continue;
			int n = v / m;
			if (m < n)swap(m, n);

			long long d = m;
			long long e = n;

			if (d*d - e*e == 0)continue;

			printf("%lld %lld\n", d*d - e*e, d*d + e*e);
			return 0;


		}
	}
	else {

		// v : odd

		// then n, (n^2-1) / 2, (n^2+1)

		long long flag = ((v*v) - 1) >> 1;

		if (flag > 0) {
			printf("%lld %lld\n", ((v*v) - 1) >> 1, ((v*v) + 1) >> 1);
			return 0;
		}

	}

	printf("-1\n");
}
