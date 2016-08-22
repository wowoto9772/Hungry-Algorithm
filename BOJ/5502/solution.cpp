#include <stdio.h>
#include <limits.h>

#include <string.h>
#include <algorithm>

using namespace std;

char str[5003];

int dp[5003][5003];

int dy(int l, int r) {

	if (l >= r)return 0;
	int &ret = dp[l][r];

	if (ret != -1)return ret;

	ret = INT_MAX;

	if (str[l] == str[r])ret = min(ret, dy(l + 1, r - 1));
	ret = min(ret, 1 + min(dy(l + 1, r), dy(l, r - 1)));

	return ret;

}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			dp[i][j] = -1;
		}
	}

	scanf("%s", str);

	printf("%d\n", dy(0, n - 1));

}