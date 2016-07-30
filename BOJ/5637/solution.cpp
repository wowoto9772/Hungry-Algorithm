#include <stdio.h>
#include <string.h>

char str[103];
char ans[103];

bool chk(char *a) {
	int s = strlen(a);

	return true;
}

int main() {

	int m = 0;

	while (scanf("%s", str) == 1) {
		if (!strcmp(str, "E-N-D"))break;

		char pars[130] = { 0 };
		int s = strlen(str);
		int t = 0;

		for (int i = 0; i < s; i++) {
			if (str[i] == '-'||
				str[i] >= 'a' && str[i] <= 'z' ||
				str[i] >= 'A' && str[i] <= 'Z') {
				pars[t++] = str[i];
			}
			else {
				if (m < t) {
					strcpy(ans, pars);
				}
				for (int j = 0; j < t; j++)pars[j] = 0;
				t = 0;
			}
		}

		if (m < t) {
			m = t;
			strcpy(ans, pars);
		}
	}

	for (int i = 0; i < m; i++) {
		if (ans[i] <= 'Z' && ans[i] >= 'A')ans[i] += 'a' - 'A';
	}

	printf("%s\n", ans);

}