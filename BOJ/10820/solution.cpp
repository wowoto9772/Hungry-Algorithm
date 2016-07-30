#include <stdio.h>
#include <string.h>

char str[2000];

int main() {

	while (fgets(str, 1200, stdin)) { 
		// EOF == crtl Z(window) ctrl D(linux)
		
		int len = strlen(str);

		int C = 0, c = 0, n = 0, s = 0;

		for (int i = 0; i < len; i++) {

			if (str[i] <= 'Z' && str[i] >= 'A')C++;
			else if (str[i] <= 'z' && str[i] >= 'a')c++;
			else if (str[i] <= '9' && str[i] >= '0')n++;
			else if (str[i] == ' ')s++;

		}

		printf("%d %d %d %d\n", c, C, n, s);

	}

}