#include <stdio.h>
#include <string.h>

#include <algorithm>

using namespace std;

char str[43];
int s, dp[43];

int dy(int c) {

	if (c == s)return 1;

	if (dp[c] != -1)return dp[c];

	dp[c] = 0;

	int l = min(c + 2, s);

	if (str[c + 1]) {
		
		int d = 0;

		for (int i = c + 1; i <= l; i++) {

			d = d * 10 + str[i];
			if (d >= 1 && d <= 34) {
				dp[c] += dy(i);
			}

		}


	}

	return dp[c];

}

int main() {

	scanf("%s", str + 1);

	s = strlen(str + 1);

	for (int i = 1; i <= s; i++)str[i] -= '0', dp[i] = -1;

	dp[0] = -1;

	printf("%d\n", dy(0));

}