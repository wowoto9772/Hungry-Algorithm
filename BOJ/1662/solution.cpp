#include <stdio.h>

#include <string.h>

char str[53];
int mul[53];
int len[53];

int main() {

	scanf("%s", str);

	int s = strlen(str);

	int tp = 0;

	for (int i = 0; i < s; i++) {

		if (str[i + 1] == '(') {
			mul[tp + 1] = str[i] - '0';
			tp++;
			i++;
		}
		else if (str[i] == ')') {
			len[tp - 1] += mul[tp] * len[tp];
			len[tp] = 0;
			tp--;
		}
		else {
			len[tp]++;
		}

	}

	printf("%d\n", len[0]);

}