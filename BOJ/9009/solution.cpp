#include <stdio.h>

#define ll long long

ll p[88] = { 1, 1, };

int a[88];

int main() {

	int top = 0;

	for (int i = 2; p[i - 1] <= 1000000000; i++) {
		p[i] = p[i - 1] + p[i - 2];
		top = i;
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		int k = 0;

		for (int i = top; i >= 0; i--) {
			if (n >= p[i]) {
				a[k++] = p[i];
				n -= p[i];
			}
		}

		for (int i = k - 1; i >= 0; i--)printf("%d ", a[i]);
		printf("\n");

	}

}