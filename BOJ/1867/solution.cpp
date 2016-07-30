#include <stdio.h>
#include <memory.h>

bool chk[1003];
int cap[1003][1003];

int r, c;
#define src (0)
#define snk (r+c+1)

int dfs(int x) {

	if (chk[x])return 0;
	chk[x] = true;

	if (x == snk)return true;

	for (int i = src; i <= snk; i++) {
		if (cap[x][i] > 0) {
			if (dfs(i)) {
				cap[x][i]--;
				cap[i][x]++;
				return true;
			}
		}
	}

	return false;

}

int flow() {

	int ans = 0;

	while (true) {

		memset(chk, 0, sizeof(chk));

		if (!dfs(src)) {
			return ans;
		}

		ans++;
	}

}

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	r = c = n;

	for (int i = 1; i <= k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		cap[a][r + b] = 1;
	}

	for (int i = 1; i <= r; i++) {
		cap[src][i] = 1;
	}

	for (int i = 1; i <= c; i++) {
		cap[r + i][snk] = 1;
	}

	printf("%d\n", flow());

}