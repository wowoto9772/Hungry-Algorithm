#include <stdio.h>
#include <string.h>

char str[105];

int main() {

	int n;
	while (scanf("%d", &n) == 1 && n) {

		fgets(str, 100, stdin);

		int p = 0;

		while (n--) {
			fgets(str, 100, stdin);
			int s = strlen(str);
			s--; // except '\n'

			if (s < p)continue;

			bool flag = false;
			for (int i = p; i < s && !flag; i++) {
				if (str[i] == ' '){
					p = i;
					flag = true;
				}
			}

			if (!flag)p = s;
		}

		printf("%d\n", ++p);

	}

}