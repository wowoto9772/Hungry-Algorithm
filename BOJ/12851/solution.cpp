#include <stdio.h>
#include <queue>

using namespace std;

int k;

int chk[200003];
int dp[200003];

int dy(int c) {

	if (chk[c] > chk[k])return 0;
	else if (chk[c] == -1)return 0;
		
	if (dp[c] != -1)return dp[c];

	dp[c] = 0;

	int ncst = chk[c] + 1;

	if (c && ncst == chk[c - 1]) {
		dp[c] += dy(c - 1);
	}
	if (c + 1 <= 200000 && ncst == chk[c + 1])dp[c] += dy(c + 1);
	if ((c << 1) <= 200000 && ncst == chk[c << 1])dp[c] += dy(c << 1);

	return dp[c];

}

int df[] = { -1, 1, 0 };

int main() {

	int x;
	scanf("%d %d", &x, &k);

	for (int i = 0; i <= 200000; i++) {
		chk[i] = -1;
		dp[i] = -1;
	}

	queue <int> q;
	q.push(x);

	chk[x] = 0;

	while (!q.empty() && chk[k] == -1) {

		int f = q.front(); q.pop();

		df[2] = f;

		for (int i = 0; i < 3; i++) {
			int nf = f + df[i];
			if (nf >= 0 && nf <= 200000) {
				if (chk[nf] == -1) {
					chk[nf] = chk[f] + 1;
					q.push(nf);
				}
			}
		}

	}

	dp[k] = 1;

	printf("%d\n", chk[k]);

	printf("%d\n", dy(x));
}