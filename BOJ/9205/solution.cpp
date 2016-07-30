#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int x[103], y[103];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n + 2; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}

		bool chk[103] = { 0 };

		queue <int> q;
		q.push(1);
		chk[1] = true;

		while (!q.empty() && !chk[n+2]) {
			int f = q.front(); q.pop();
			for (int i = 1; i <= n + 2; i++) {
				if (chk[i])continue;

				int c = abs(x[f] - x[i]) + abs(y[f] - y[i]);

				if (c <= 1000) {
					chk[i] = true;
					q.push(i);
				}
			}
		}

		printf("%s\n", chk[n + 2] ? "happy" : "sad");
	}

}