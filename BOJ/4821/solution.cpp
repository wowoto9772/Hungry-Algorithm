#include <stdio.h>
#include <string.h>

char str[1003];
char cur[1003];

bool prnt[1003];

int main() {

	int lim;
	int p, q;

	while (scanf("%d", &lim) && lim) {

		fgets(str, sizeof(str), stdin); // for buffer

		for (int i = 1; i <= lim; i++)prnt[i] = false;

		fgets(str, sizeof(str), stdin);

		int s = strlen(str);

		for (int i = 0; i < s; i++) {
			if (str[i] == ',')str[i] = ' ';
			else if (str[i] == '\n')str[i] = ' ';
		}

		for (int i = 0; i < s; i++) {
			if (str[i] != ' ') {

				sscanf(str + i, "%s", cur);

				int ss = strlen(cur);

				bool hy = false;

				for (int j = 0; j < ss; j++) {
					if (cur[j] == '-')hy = true;
				}

				if (!hy) {
					sscanf(cur, "%d", &p);
					if (p <= lim)prnt[p] = true;
				}
				else {
					sscanf(cur, "%d-%d", &p, &q);
					if (p <= q) {
						if (q > lim)q = lim;
						for (int j = p; j <= q; j++)prnt[j] = true;
					}
				}

				i += ss - 1;

			}
		}

		int c = 0;
		for (int i = 1; i <= lim; i++) {
			c += prnt[i];
		}


		printf("%d\n", c);
	}



}