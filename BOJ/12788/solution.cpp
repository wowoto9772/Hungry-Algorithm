#include <stdio.h>
#include <algorithm>

using namespace std;

int c[1003];

int main() {

	int n;
	scanf("%d", &n);

	int m, k;
	scanf("%d %d", &m, &k);

	m *= k;

	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}

	sort(c, c + n);

	k = 0;

	int x = 0;
	for (int i = n - 1; i >= 0; i--) {
		x += c[i];
		k++;
		if (x >= m) {
			printf("%d\n", k);
			return 0;
		}
	}

	printf("STRESS\n");

}