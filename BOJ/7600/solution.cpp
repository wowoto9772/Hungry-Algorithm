#include <stdio.h>
#include <string.h>

char str[503];

int main() {

	while (fgets(str, 500, stdin)) {

		if (!strcmp(str, "#\n"))break;

		bool chk['z' + 3] = { 0 };

		int s = strlen(str);

		s--; // last character : '\n'

		for (int i = 0; i < s; i++)chk[str[i]] = true;
		
		int c = 0;

		for (int i = 'A'; i <= 'Z'; i++) {
			if (chk[i] || chk[i + 'a' - 'A'])c++;
		}

		printf("%d\n", c);

	}

}