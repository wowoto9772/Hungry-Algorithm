#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int dp[103][103][103];

int dy(int a, int b, int c) {

	int &ret = dp[a][b][c];

	if (ret != -1)return ret;

	ret = 0;

	for (int i = b + 1; i <= c - 1; i++) {
		ret = max(ret, 1 + dy(b, i, c));
	}
	
	for (int i = a + 1; i <= b - 1; i++) {
		ret = max(ret, 1 + dy(a, i, b));
	}

	return ret;

}

int main() {

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	memset(dp, 0xff, sizeof(dp));

	printf("%d\n", dy(a, b, c));

}