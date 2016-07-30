#include <stdio.h>
#include <string.h>

char str[53];
int s;
int dp[54][4][6];

bool isVowl(int s) {
	if (s == 'A' || s == 'E' || s == 'I'
		|| s == 'O' || s == 'U')return true;

	return false;
}

int dy(int c, int vo, int co) {

	if (vo == 3 || co == 5) { // is Ugly
		return 1;
	}
	else if (c == s) { // is Nice
		return 2;
	}

	if (dp[c][vo][co] != -1)return dp[c][vo][co];

	dp[c][vo][co] = 0;

	char x = str[c];

	if (x == '?') {
		dp[c][vo][co] |= dy(c + 1, vo + 1, 0); // assume vowl
		dp[c][vo][co] |= dy(c + 1, 0, co + 1); // assume consonant
	}
	else {
		if (isVowl(x))dp[c][vo][co] = dy(c + 1, vo + 1, 0);
		else
			dp[c][vo][co] = dy(c + 1, 0, co + 1);
	}

	return dp[c][vo][co];
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%s", str);

		s = strlen(str);

		for (int i = 0; i < s; i++) {
			for (int j = 0; j <= 3; j++) {
				for (int k = 0; k <= 5; k++) {
					dp[i][j][k] = -1;
				}
			}
		}

		if (dy(0, 0, 0) == 3)printf("42\n");
		else if (dy(0, 0, 0) == 1)printf("UGLY\n");
		else
			printf("NICE\n");

	}
}