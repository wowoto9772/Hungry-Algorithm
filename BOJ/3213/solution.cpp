#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <map>

using namespace std;

map <int, map<int, map<int, int> > > dp;

int dy(int a, int b, int c) {
	
	if (!a && !b && !c)return 0;
	if (dp[a][b].find(c) != dp[a][b].end()) return dp[a][b][c];

	dp[a][b][c] = a + b + c;

	if (a && c)dp[a][b][c] = min(dp[a][b][c], 1 + dy(a - 1, b, c - 1));
	if (b >= 2)dp[a][b][c] = min(dp[a][b][c], 1 + dy(a, b - 2, c));
	if (a && b) {
		if (a >= 2)dp[a][b][c] = min(dp[a][b][c], 1 + dy(a - 2, b - 1, c));
		dp[a][b][c] = min(dp[a][b][c], 1 + dy(a - 1, b - 1, c));
	}

	if (a)dp[a][b][c] = min(dp[a][b][c], 1 + dy(a - 1, b, c));
	if (b)dp[a][b][c] = min(dp[a][b][c], 1 + dy(a, b-1, c));
	if (c)dp[a][b][c] = min(dp[a][b][c], 1 + dy(a, b, c-1));

	return dp[a][b][c];

}

int main() {

	int n;
	scanf("%d", &n);

	int a = 0, b = 0, c = 0;

	while (n--) {
		int x, y;
		scanf("%d/%d", &x, &y);

		if (x == 1) {
			if (y == 2) {
				b++;
			}
			else
				a++;
		}
		else {
			c++;
		}
	}

	int s = min(a, c);

	a -= s, c -= s;

	int ans = s;

	s = min(a / 2, b);

	ans += s;

	a -= 2 * s, b -= s;

	ans += b / 2;
	b %= 2;

	printf("%d\n", ans + dy(a, b, c));

}