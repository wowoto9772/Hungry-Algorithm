#include <stdio.h>
#include <vector>

using namespace std;

int A[505], B[505];

int dp[505][505];
int pi[505][505], pj[505][505];

int f[505];

int main() {

	int a, b;
	scanf("%d", &a);

	for (int i = 1; i <= a; i++)scanf("%d", &A[i]);

	scanf("%d", &b);

	for (int i = 1; i <= b; i++)scanf("%d", &B[i]);

	int m = 0, mi = 0, mj = 0;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			dp[i][j] = 0;
			if (A[i] == B[j]) {
				for (int k = 1; k < j; k++) {
					if (B[k] < B[j] && dp[i][j] < dp[f[k]][k]) {
						dp[i][j] = dp[f[k]][k];
						pi[i][j] = f[k];
						pj[i][j] = k;
					}
				}

				dp[i][j]++;

				if (m < dp[i][j]) {
					m = dp[i][j];
					mi = i;
					mj = j;
				}
			}
		}
		for (int j = 1; j <= b; j++) {
			if (A[i] == B[j])f[j] = i;
		}
	}

	printf("%d\n", m);

	vector <int> p;

	while (mi && mj) {
		int nmi = pi[mi][mj];
		int nmj = pj[mi][mj];

		p.push_back(A[mi]);

		mi = nmi, mj = nmj;
	}

	for (int i = p.size() - 1; i >= 0; i--)printf("%d ", p[i]);

}