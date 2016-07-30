#include <stdio.h>
#include <algorithm>

using namespace std;

int e[20003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &e[i]);
	}

	if (n == 1)printf("%d\n", e[1]);
	else {

		sort(e + 1, e + 1 + n);

		printf("%d\n", e[n / 2]);

	}

}