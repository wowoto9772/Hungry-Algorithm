#include <stdio.h>
#include <string.h>

char str[12345];

int main() {

	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		
		printf("String #%d\n", i);

		scanf("%s", str);

		int s = strlen(str);

		for (int j = 0; j < s; j++) {
			str[j]++;
			if (str[j] > 90)str[j] -= 26;
			printf("%c", str[j]);
		}

		printf("\n\n");

	}
}