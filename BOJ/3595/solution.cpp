#include <stdio.h>
#include <limits.h>

#define ll long long

int main() {

	int n;
	scanf("%d", &n);

	int ans = INT_MAX, x, y, z;

	for (ll a = 1; a <= n; a++) {
		for (ll b = a; a*b <= n; b++) {
			for (ll c = b; a*b*c <= n; c++) {
				if (a*b*c == n) {
					int cmp = 2 * (a*b + b*c + c*a);
					if (ans > cmp) {
						ans = cmp;
						x = a, y = b, z = c;
					}
				}
			}
		}
	}

	printf("%d %d %d\n", x, y, z);

}