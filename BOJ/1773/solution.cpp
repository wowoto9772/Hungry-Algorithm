#include <stdio.h>

bool chk[2000003];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {

		int a;
		scanf("%d", &a);

		for (int j = a; j <= m; j += a) {
			chk[j] = true;
		}

	}
	
	int c = 0;
	for (int i = 1; i <= m; i++)c += chk[i];

	printf("%d\n", c);

}