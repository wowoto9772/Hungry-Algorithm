#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char p[5], pp[5];
char s[5];

bool chk[10][10];

int main() {

	scanf("%s", p);

	strcpy(s, p);

	bool flag = true;
	for (int i = 1; i <= 35; i++) {
		scanf("%s", pp);
		int c = abs(p[0] - pp[0]) * abs(p[1] - pp[1]);
		if (c != 2)flag = false;
		strcpy(p, pp);
		if (!chk[p[0] - 'A'][p[1] - '1']) {
			chk[p[0] - 'A'][p[1] - '1'] = true;
		}
		else {
			flag = false;
		}
	}

	int c = abs(p[0] - s[0]) * abs(p[1] - s[1]);
	if (c != 2)flag = false;

	printf("%s\n", flag ? "Valid" : "Invalid");

}