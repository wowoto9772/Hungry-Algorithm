#include <stdio.h>

int chk[100];

int main() {

	int v, p;
	scanf("%d %d", &v, &p);

	int c = 0;
	int pv = v;

	while (true) {
	
		int n = (pv * v) % p;

		if (chk[n]) {
			c++;
			printf("%d\n", c - chk[n]);
			break;
		}
		else {
			chk[n] = ++c;
		}

		pv = n;

	}

}