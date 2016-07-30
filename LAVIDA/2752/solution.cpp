#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

#define ll long long

char str[1003];
ll dp[1003];
int n;
int con['Z' + 3];

ll dy(int c) {

	if (dp[c] != -1)return dp[c];

	dp[c] = INT_MAX;

	for (int i = c + 1; i < n; i++) {
		if (con[str[c]] == str[i]) {
			dp[c] = min(dp[c], (i - c)*(i - c) + dy(i));
		}
	}

	return dp[c];

}

int main() {

	con['B'] = 'O';
	con['O'] = 'J';
	con['J'] = 'B';

	scanf("%d", &n);

	scanf("%s", str);

	for (int i = 0; i < n - 1; i++)dp[i] = -1;

	int d = dy(0);

	if (d == INT_MAX)d = -1;

	printf("%d\n", d);

}

/*
13
BJBBJOOOJJJJB
*/