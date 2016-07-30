#include <stdio.h>

#define mid 200000

using namespace std;

bool c[400003];

int e[5003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &e[i]);
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j < i; j++) {

			int k = e[i] - e[j];

			if (c[k + mid]) {
				ans++;
				break;
			}

		}

		for (int j = 1; j <= i; j++) {
			c[e[i] + e[j] + mid] = true;
		}

	}

	printf("%d\n", ans);

}