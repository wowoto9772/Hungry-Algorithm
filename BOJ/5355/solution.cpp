#include <stdio.h>
#include <string.h>

char str[12345 + 3];

int main() {

	int t;
	scanf("%d", &t);

	fgets(str, 12345, stdin); // for buffer

	while (t--) {

		fgets(str, 12345, stdin);

		int s = strlen(str);
		s--; // last character : '\n'

		double val;

		sscanf(str, "%lf", &val);

		int l = 0;

		for (int i = 0; i < s; i++) {
			if (str[i] == ' ') {
				l = i + 1;
				break;
			}
		}

		for (int i = l; i < s; i ++) {
			if (str[i] == '@')val *= 3;
			else if (str[i] == '%')val += 5;
			else if (str[i] == '#')val -= 7;
		}

		printf("%.2lf\n", val);

	}

}