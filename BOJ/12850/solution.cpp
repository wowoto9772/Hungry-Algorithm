#include <stdio.h>
#include <memory.h>

#define mod 1000000007
#define ll long long

void multy(ll a[][8], ll b[][8], ll tmp[][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < 8; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
				tmp[i][j] %= mod;
			}
		}
	}
}

int main() {

	ll m[8][8] = { 0 }, c[8][8] = { 0 }, tmp[8][8];

	m[0][1] = m[0][2] = 1;
	m[1][2] = m[1][3] = 1;
	m[2][3] = m[2][4] = 1;
	m[3][4] = m[3][5] = 1;
	m[4][5] = m[4][6] = 1;
	m[5][7] = 1;
	m[6][7] = 1;

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 8; j++) {
			m[j][i] = m[i][j];
		}
		c[i][i] = 1; // identity
	}

	int t;
	scanf("%d", &t);

	while (t) {
		if (t & 1) {
			multy(c, m, tmp);
			memcpy(c, tmp, sizeof(c));
		}
		t >>= 1;
		multy(m, m, tmp);
		memcpy(m, tmp, sizeof(m));
	}

	printf("%lld\n", c[0][0]);

}