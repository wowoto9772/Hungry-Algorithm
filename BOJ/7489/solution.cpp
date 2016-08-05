#include <stdio.h>
#include <algorithm>

using namespace std;

bool p[1003];
int P[255];
int c[255];
int top;

int main() {

	int top = 0;

	for (int i = 2; i*i <= 1000; i++) {
		if (p[i])continue;
		for (int j = i*i; j <= 1000; j += i) {
			p[j] = true;
		}
	}

	for (int i = 2; i <= 1000; i++)if (!p[i])P[top++] = i;

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		int x = 1;

		for (int i = 0; i < top && P[i] <= n; i++) {

			c[i] = 0;

			for (int j = P[i]; j <= n; j *= P[i]) {
				c[i] += n / j;
			}

		}

		int mini = min(c[0], c[2]);

		c[0] -= mini;
		c[2] -= mini;

		for (int i = 0; i < top && P[i] <= n; i++) {

			for (int j = 1; j <= c[i]; j++) {
				x *= P[i];
				x %= 10;
			}

		}

		printf("%d\n", x);

	}

}