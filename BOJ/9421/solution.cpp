#include <stdio.h>

bool p[1000003];
int chk[1000003];

// 81*6+3

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 2; i*i <= n; i++) {
		if (!p[i]) {
			for (int j = i*i; j <= n; j += i)p[j] = true;
		}
	}

	for (int i = 2; i <= n; i++) {
		
		if (p[i])continue;

		int v = i;

		while (chk[v] != i) {

			chk[v] = i;

			int nv = 0;

			while (v) {

				int d = v % 10;
				nv += d*d;
				v /= 10;

			}

			v = nv;

		}

		if (v == 1)printf("%d\n", i);

	}

}