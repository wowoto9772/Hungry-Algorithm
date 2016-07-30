#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#define ll long long

using namespace std;

char tar[2503];
char wrd[53][53];
int n;
int s[53];

ll dp[2503];

int cst(int le, int ri, int v) {

	int c['z' + 3] = { 0 };
	int ret = 0;

	for (int i = le; i <= ri; i++) {
		c[tar[i]]++;
		ret += (tar[i] != wrd[v][i-le]);
		c[wrd[v][i - le]]--;
	}

	for (int i = 'a'; i <= 'z'; i++)if (c[i])return -1;

	return ret;

}

ll dy(int c) {
	
	if (dp[c] != -1)return dp[c];

	dp[c] = INT_MAX;

	for (int i = 1; i <= n; i++) {
		if (c + s[i] <= s[0]) {
			int m = cst(c, c + s[i] - 1, i);
			if (m != -1) {
				dp[c] = min(dp[c], m + dy(c + s[i]));
			}
		}
	}

	return dp[c];

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%d", &n);

		scanf("%s", tar); // target string

		s[0] = strlen(tar);

		for (int i = 0; i < s[0]; i++)dp[i] = -1;

		for (int i = 1; i <= n; i++) {
			scanf("%s", wrd[i]);
			s[i] = strlen(wrd[i]);
		}

		dp[s[0]] = 0;

		int g = dy(0);

		if (g == INT_MAX)g = -1;

		printf("%d\n", g);

	}

}