#include <stdio.h>
#include <string.h>

char str[23];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%s", str);

		int s = strlen(str);

		for (int i = 0; i < s; i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				str[i] += 'a' - 'A';
			}
		}

		printf("%s\n", str);

	}

}