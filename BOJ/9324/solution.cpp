#include <stdio.h>
#include <string.h>

char str[100003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%s", str);

		int s = strlen(str);

		int c['Z' + 3] = { 0 };

		bool fake = false;

		for (int i = 0; i < s && !fake; i++) {
			c[str[i]]++;
			if (!(c[str[i]] % 3)) {
				if (i + 1 < s && str[i + 1] == str[i]) {}
				else
					fake = true;
				i++;
			}
		}

		printf("%s\n", fake ? "FAKE" : "OK");

	}

}