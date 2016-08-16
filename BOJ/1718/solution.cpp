#include <stdio.h>
#include <string.h>

char str[30003];
char enc[30003];

int main() {

	fgets(str, sizeof(str), stdin);

	int s = strlen(str);

	if (str[s - 1] == '\n')s--;

	scanf("%s", enc);

	int e = strlen(enc);
	int t = 0;

	for (int i = 0; i < s; i++) {

		if (str[i] == ' ')printf(" ");
		else {
			str[i] -= enc[t] - ('a'-1);
			if (str[i] < 'a')str[i] += 26;
			printf("%c", str[i]);
		}

		t++;
		if (t == e)t = 0;

	}

}