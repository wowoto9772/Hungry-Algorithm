#include <stdio.h>
#include <string.h>

char a[13][13];

int main() {

	int n;
	scanf("%d", &n);

	bool flag = true;

	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);

		if (!flag)continue;

		if (i) {
			if (a[i - 1][strlen(a[i - 1]) - 1] != a[i][0]) {
				flag = false;
			}
		}
	}

	printf("%s\n", flag ? "YES" : "NO");

}