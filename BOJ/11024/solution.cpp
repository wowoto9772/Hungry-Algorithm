#include <stdio.h>
#include <string.h>

char str[10000 * 100 + 5000];

int main() {

	int t;
	scanf("%d", &t);

	fgets(str, 1000000, stdin); // for buffer

	while (t--) {

		fgets(str, 1000000, stdin);

		int s = strlen(str);

		int ans = 0, v = 0;

		for (int i = 0; i < s; i++) {
			if (str[i] == ' ' || str[i] == '\n') {
				ans += v;
				v = 0;
			}
			else {
				v = v * 10 + str[i] - '0';
			}
		}

		printf("%d\n", ans);

	}

}