#include <stdio.h>
#include <string.h>

char str[35];

int d[35];

int main() {

	for (int i = 0; i < 31; i++) {
		d[i] = (2 << i) - 1;
	}

	while (scanf("%s", str) == 1) {
		
		if (!strcmp(str, "0"))break;

		int s = strlen(str);

		int a = 0;

		for (int i = s - 1; i >= 0; i--) {
			a += (str[i] - '0') * d[s - 1 - i];
		}

		printf("%d\n", a);

	}

}