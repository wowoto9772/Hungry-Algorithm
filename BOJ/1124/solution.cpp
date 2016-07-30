#include <stdio.h>
#define ll long long

bool p[100003] = { true, true };
int P[10003];

int main() {

	int top = 0;

	for (ll i = 2; i <= 100000; i++) {
		if (!p[i]) {
			P[top++] = i;
			if (i*i <= 100000) {
				for (int j = i*i; j <= 100000; j += i) {
					p[j] = true;
				}
			}
		}
	}

	int a, b;
	scanf("%d %d", &a, &b);

	int y = 0;

	for (int i = a; i <= b; i++) {

		int c = i;
		int x = 0;

		for (int j = 0; j < top && P[j] <= c; j++) {

			while (!(c % P[j])) {
				c /= P[j];
				x++;
			}

		}

		if (c != 1)x++;

		if (!p[x])y++;

	}

	printf("%d\n", y);

}