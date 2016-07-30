#include <stdio.h>

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	int j = 0;

	for (int i = 1; i <= n; i++) {
		j = (j + m) % i;
	}

	printf("%d\n", j + 1);

}

/*
#include <stdio.h>
#define ll long long

int main() {

ll n, k;
scanf("%lld %lld", &n, &k);

ll j, r = 0;

for (ll i = 1; i <= n;) {
j = (i - r - 1) / k;
if (i + j > n)j = n - i;
if (j == 0)j = 1;
r = (r + k*j) % i;
i += j;
}

printf("%lld\n", r + 1);
}

큰수에 대해서도 나옴.
*/