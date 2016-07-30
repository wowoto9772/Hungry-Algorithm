#include <stdio.h>
#include <string.h>

char str[1003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%s", str);
		int s = strlen(str);
		s--;

		if (str[s / 2] == str[s / 2 + 1]) {
			printf("Do-it\n");
		}
		else {
			printf("Do-it-Not\n");
		}
	}

}