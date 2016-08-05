#include <stdio.h>
#include <string.h>

char s[83];

int main()
{
	while (fgets(s, sizeof(s), stdin)) {
		if (!strcmp(s, "#\n") || !strcmp(s, "#"))break;
		int k = strlen(s);

		for (int i = 0; i < k; i++) {
			if (s[i] == ' ')printf("%%20");
			else if (s[i] == '!')printf("%%21");
			else if (s[i] == '$')printf("%%24");
			else if (s[i] == '%')printf("%%25");
			else if (s[i] == '(')printf("%%28");
			else if (s[i] == ')')printf("%%29");
			else if (s[i] == '*')printf("%%2a");
			else
				printf("%c", s[i]);
		}

		if (s[k - 1] != '\n')printf("\n");
	}
}