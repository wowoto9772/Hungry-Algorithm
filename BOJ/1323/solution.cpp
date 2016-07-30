#include <stdio.h>
#define ll long long

int dig(int v) {

	int ret = 0;

	if (v) {
		while (v) {
			v /= 10;
			ret++;
		}
	}
	else {
		ret++;
	}

	return ret;

}

bool chk[100003];

int main() {

	ll d[12] = { 1 };

	for (int i = 1; i <= 10; i++)d[i] = d[i - 1] * 10LL;

	int n, k;

	scanf("%d %d", &n, &k);

	ll dg = d[dig(n)];

	ll v = 0;

	for (int i = 1;; i++) {

		v *= dg;
		v += n;

		v %= k;
		
		if (!v) {
			printf("%d\n", i);
			return 0;
		}

		if (chk[v]) {
			printf("-1\n");
			return 0;
		}	

		chk[v] = true;

	}

}

/*
	1000000000 7
*/