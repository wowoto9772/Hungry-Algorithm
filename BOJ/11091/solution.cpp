#include <stdio.h>
#include <string.h>

char str[203];

int main() {

	int t;
	scanf("%d", &t);

	fgets(str, 200, stdin); // for buffer

	while (t--) {

		fgets(str, 200, stdin); 

		int s = strlen(str);

		bool chk['z' + 3] = { 0 };
		int k = 0;

		for (int i = 0; i < s; i++) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				if (!chk[str[i]]) {
					k++;
					chk[str[i]] = true;
				}
			}
			else if (str[i] >= 'A' && str[i] <= 'Z') {
				if (!chk[str[i] + 'a' - 'A']) {
					k++;
					chk[str[i] + 'a' - 'A'] = true;
				}
			}
		}

		if (k == 26)printf("pangram\n");
		else {
			printf("missing ");

			for (int i = 'a'; i <= 'z'; i++)if (!chk[i])printf("%c", i);

			printf("\n");
		}

	}

}