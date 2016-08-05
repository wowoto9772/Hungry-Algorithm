#include <stdio.h>
#include <string.h>

char str[123456];

int main() {

	while (fgets(str, sizeof(str), stdin)) {

		if (!strcmp(str, "#\n"))break;

		int s = strlen(str);

		if (str[s - 1] == '\n')str[s - 1] = ' ';

		int ans = 0;

		for (int i = 0; i < s; i++) {
			if (str[i] == ' ')continue;
			ans += (i + 1) * (str[i] - 'A' + 1);
		}

		printf("%d\n", ans);

	}

}