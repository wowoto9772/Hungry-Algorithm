#include <stdio.h>
#include <memory.h>
#define ll long long

#define mod 1000007LL

ll d[202][202];
ll p[202][202];

int a, b;
ll d_(int i, int j) {
	if (i > a || j > b)return 0;
	if (i == a && j == b)return 1;

	if (d[i][j] != -1)return d[i][j];

	d[i][j] = d_(i + 1, j) + d_(i, j + 1);

	d[i][j] %= mod;

	return d[i][j];
}

int x, y;
ll y_(int i, int j) {
	if (i > x || j > y)return 0;
	if (i == x && j == y)return 1;

	if (p[i][j] != -1)return p[i][j];

	p[i][j] = y_(i + 1, j) + y_(i, j + 1);
	p[i][j] %= mod;

	return p[i][j];
}

int main() {

	scanf("%d %d", &x, &y);

	scanf("%d %d", &a, &b);

	memset(d, 0xff, sizeof(d));
	memset(p, 0xff, sizeof(p));

	printf("%lld\n", (d_(1, 1) * y_(a, b)) % mod);

}