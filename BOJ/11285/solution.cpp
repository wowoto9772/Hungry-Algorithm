#include <string.h>
#include <stdio.h>

char str[30];

int main() {

	scanf("%s", str);

	int s = strlen(str);

	for (int i = 0; i < s; i++) {
		printf("%c\n", str[i]);
	}

}