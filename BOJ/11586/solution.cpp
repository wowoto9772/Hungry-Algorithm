#include <stdio.h>
#include <algorithm>

using namespace std;

char str[103][103];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}

	int k;
	scanf("%d", &k);

	if (k == 2) {

		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n / 2; k++) {
				swap(str[i][k], str[i][n - 1 - k]);
			}
		}

	}
	else if (k == 3) {

		for (int i = 0; i < n; i++) {

			for (int k = 0; k < n / 2; k++) {
				swap(str[k][i], str[n - 1 - k][i]);
			}

		}

	}


	for (int i = 0; i < n; i++)printf("%s\n", str[i]);

}