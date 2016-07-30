#include <string.h>
#include <stdio.h>

char str[403];

char isPangram(char *a) {

	int s = strlen(a);

	bool chk['z' + 3] = { 0 };

	for (int i = 0; i < s; i++)chk[str[i]] = true;

	for (int i = 'a'; i <= 'z'; i++) {
		if (!chk[i])return 'N';
	}

	return 'Y';

}

int main() {

	while (fgets(str, 400, stdin)) {

		if (!strcmp(str, "*\n"))break;

		printf("%c\n", isPangram(str));

	}

}