#include <stdio.h>
#include <string.h>

char str[103];

int main() {

	scanf("%s", str + 1);

	str[0] = '|';

	int s = strlen(str);

	int c = 0, a = 0;

	int l = 0;

	for (int i = 0; i < s; i++) {
		if (str[i] == '|') {
			if (str[i + 1] == 'C' || str[i + 1] == 'F' || str[i + 1] == 'G') {
				c++;
			}
			else if (str[i + 1] == 'A' || str[i + 1] == 'D' || str[i + 1] == 'E') {
				a++;
			}
			if (c == a) {
				if (str[s - 1] == 'A' || str[s - 1] == 'D' || str[s - 1] == 'E') {
					l = 1;
				}
				else {
					l = 0;
				}
			}
		}
	}

	if (c > a)printf("C-major");
	else if (c < a)printf("A-minor");
	else {
		if (l)printf("A-minor");
		else
			printf("C-major");
	}

}