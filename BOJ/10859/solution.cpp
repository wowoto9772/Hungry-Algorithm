#include <stdio.h>

#define ll long long

int main() {

	ll n;
	scanf("%lld", &n);

	bool flag = false;

	if (n == 1)flag = true;

	for (ll i = 2; !flag && i*i <= n; i++) {
	
		if (n%i)continue;
		flag = true;

	}

	ll m = 0;
	while (n && !flag) {
		m = m * 10;
		int k = n % 10;
		if (k <= 2 || k == 5 || k == 8)m += k;
		else if (k == 6)m += 9;
		else if (k == 9)m += 6;
		else
			flag = true;
		n /= 10;
	}

	for (ll i = 2; !flag && i*i <= m; i++) {

		if (m%i)continue;
		flag = true;

	}

	printf("%s\n", flag ? "no" : "yes");

}