#include <stdio.h>
#include <algorithm>

using namespace std;

int g[1003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &g[i]);
	}

	for (int i = 1; i <= n; i++) {

		int m;
		scanf("%d", &m);

		g[i] -= m;

	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {

		while (g[i]) {

			int mini = g[i];

			int k = i;

			for (int j = i + 1; j <= n; j++) {

				if (mini * g[j] > 0) {

					k = j;

					if (mini > 0)mini = min(mini, g[j]);
					else
						mini = max(mini, g[j]);

				}
				else {
					break;
				}

			}

			ans += abs(mini);

			for (int j = i; j <= k; j++)g[j] -= mini;

		}

	}

	printf("%d\n", ans);

}