#include <stdio.h>
#include <algorithm>

using namespace std;

int d[10003];

int main() {

	for (int i = 1; i*(i + 1) < 10000; i++) {
		for (int j = i*(i + 1); j <= 10000; j++) {
			d[j] = max(d[j], i);
		}
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		printf("%d\n", d[n]);

	}

}