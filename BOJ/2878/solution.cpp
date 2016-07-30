#include <stdio.h>
#include <algorithm>

using namespace std;

int x[100003];

int main() {

	unsigned long long m;
	int n;
	scanf("%llu %d", &m, &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
		m -= x[i];
	}

	m *= -1;

	sort(x + 1, x + 1 + n);

	unsigned long long ans = 0;
	for (int i = 1; i <= n; i++) {
		unsigned long long w = min((unsigned long long)x[i], m / (n - i + 1));
		ans += w*w;
		m -= w;
	}

	printf("%llu\n", ans);

}