#include <stdio.h>
#include <algorithm>

using namespace std;

int s[404][404][2];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) {
			int e;
			scanf("%d", &e);

			s[i][j][0] = s[i - 1][j - 1][0] + e;
			s[i][j][1] = s[i - 1][j + 1][1] + e;
		}
	}

	int ans = -1003;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				int g = (k - j);
				if (i + g > n)break;
				ans = max(ans, (s[i + g][k][0] - s[i-1][j-1][0]) - (s[i + g][j][1] - s[i-1][k+1][1]));
			}
		}
	}

	printf("%d\n", ans);

}