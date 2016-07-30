#include <stdio.h>
#include <string.h>
#define strx(a) str[s-a]

char excep[23][23];
char excep2[23][23];
char str[23];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)scanf("%s %s", excep[i], excep2[i]);

	for (int i = 1; i <= m; i++) {
		scanf("%s", str);
		bool flag = false;

		for (int j = 1; j <= n && flag == false; j++) {
			if (strcmp(str, excep[j]) == 0) {
				printf("%s\n", excep2[j]);
				flag = true;
			}
		}

		if (flag == false) {
			int s = strlen(str);
			if ((strx(2) != 'a' && strx(2) != 'e' && str[s - 3] != 'i' &&
				strx(2) != 'o' && strx(2) != 'u') && strx(1) == 'y') {
				for (int i = 0; i < s - 1; i++)printf("%c", str[i]);
				printf("ies\n");
			}
			else if (strx(1) == 'o' || strx(1) == 's' || strx(1) == 'x' ||
				strx(1) == 'h' && (strx(2) == 'c' || strx(2) == 's')) {
				printf("%s", str);
				printf("es\n");
			}
			else {
				printf("%s", str);
				printf("s\n");
			}
		}
	}
}