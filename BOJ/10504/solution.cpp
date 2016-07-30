#include <stdio.h>

#define ll long long

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		n <<= 1;

		// (first + last) * (cnt) / 2 = N
		// 2N = (first + last) * cnt

		bool flag = false;
		for (ll i = 2; i*i <= n && !flag; i++) {

			if (n % i)continue;

			int k = n / i;
			k -= (i - 1);

			if (k % 2)continue;

			// possible

			flag = true;
			k /= 2;

			n /= 2;
			printf("%d = ", n);
			for (int j = k; j < k + i; j++) {
				if (j != k)printf(" + ");
				printf("%d", j);
			}printf("\n");
		}

		if (!flag)printf("IMPOSSIBLE\n");

	}

}