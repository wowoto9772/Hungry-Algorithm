#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 54321

using namespace std;

int dp[2003][2003];
char str[2003];
int s;

int dy(int c, int p) {

	if (c == s) {
		if (p)return MAX;
		return 0;
	}

	if (dp[c][p] != -1)return dp[c][p];

	if (p) {
		if (str[c] == '}')dp[c][p] = dy(c + 1, p - 1);
		else {
			dp[c][p] = min(1 + dy(c + 1, p - 1), dy(c + 1, p + 1));
		}
	}
	else {
		if (str[c] == '{')dp[c][p] = dy(c + 1, p + 1);
		else {
			dp[c][p] = 1 + dy(c + 1, p + 1);
		}
	}

	return dp[c][p];

}

int main() {

	int tc = 0;

	while (scanf("%s", str) == 1 && str[0] != '-') {

		s = strlen(str);

		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++) {
				dp[i][j] = -1;
			}
		}

		int p = 0;

		if (str[0] == '}')p = 1;

		printf("%d. %d\n", ++tc, p + dy(1, 1));

	}

}