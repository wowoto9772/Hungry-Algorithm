#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char a[23], b[23];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%s %s", a, b);

		int s = strlen(a);

		int d = 0;

		printf("Distances: ");
		for (int i = 0; i < s; i++) {
			int k = b[i] - a[i];
			if (k < 0)k += 26;
			printf("%d ", k);
		}printf("\n");

	}

}