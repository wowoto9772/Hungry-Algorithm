#include <stdio.h>
#include <limits.h>

#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll dp[1003][1003];

vector <int> a, b;

ll dy(int x, int y) {

	if (y == b.size())return 0;
	else if (x >= a.size())return LLONG_MAX / 2;

	if (dp[x][y] != -1)return dp[x][y];

	dp[x][y] = min({ dy(x + 1, y), dy(x + 1, y + 1) + abs(a[x] - b[y]) });

	return dp[x][y];

}

int main() {

	int x, y;
	scanf("%d %d", &x, &y);

	a.resize(x);
	b.resize(y);

	for (int i = 0; i < x; i++)scanf("%d", &a[i]);
	for (int i = 0; i < y; i++)scanf("%d", &b[i]);

	if (x < y) {
		int k = x;
		x = y;
		y = k;
	}

	for (int i = 0; i < x; i++)for (int j = 0; j < y; j++)dp[i][j] = -1;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if (a.size() < b.size()) {

		vector <int> c = a;

		a = b;
		b = c;

	}

	printf("%lld\n", dy(0, 0));

}