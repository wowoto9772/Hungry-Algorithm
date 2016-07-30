#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

class ele {
public:
	int r, c;
}I[503];

int dp[502][502];

int main()
{

	int n;
	scanf("%d", &n);

	memset(dp, 0x4f, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &I[i].r, &I[i].c);
		dp[i][i] = 0;
	}

	for (int a = 1; a < n; a++) {
		for (int i = 1; i <= n; i++) {
			int k = i + a;
			if (k > n)break;
			for (int j = i; j < k; j++) {
				if (I[j].c == I[j + 1].r) {
					int x = I[i].r * I[j].c * I[k].c;
					dp[i][k] = min(dp[i][k], dp[i][j] + dp[j + 1][k] + x);
				}
			}
		}
	}

	printf("%d\n", dp[1][n]);
}