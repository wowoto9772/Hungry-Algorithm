#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char A[1003], B[1003];

int dp[1003][1003];

int main() {

	scanf("%s %s", A + 1, B + 1);

	int a = strlen(A + 1), b = strlen(B + 1);

	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (A[i] == B[j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}

	printf("%d\n", a + b - dp[a][b]);

}