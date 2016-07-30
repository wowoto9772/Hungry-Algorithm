#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

int cyc(char str[]) {

	int s = strlen(str);
	char out[1003] = { 0 };

	map <string, bool> chk;

	chk[string(str)] = true;

	for (int x = 1;; x++) {

		out[0] = str[0];

		int r = s - 1;
		int l = 1;
		int e = 0;

		// reverse operation
		for (int i = 1; i < s; i += 2)out[r--] = str[i];
		for (int i = 2; i < s; i += 2)out[l++] = str[i];

		for (int i = 1; i < s; i++)str[i] = out[i];

		if (chk[string(str)])return x;

	}
}

char str[1003];
char out[1003];

int main() {

	int n;
	scanf("%d", &n);

	scanf("%s", str);

	int s = strlen(str);

	int c = cyc(str);

	if (c == 1) {
		n = 0;
		strcpy(out, str);
	}
	else {
		n %= c;
	}

	for (int x = 1; x <= n; x++) {

		out[0] = str[0];

		int r = s - 1;
		int l = 1;
		int e = 0;

		for (int i = 1; i < s; i += 2)out[r--] = str[i];
		for (int i = 2; i < s; i += 2)out[l++] = str[i];

		for (int i = 1; i < s; i++)str[i] = out[i];

	}

	printf("%s\n", out);

}