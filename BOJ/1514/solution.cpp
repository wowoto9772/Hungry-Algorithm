#include <stdio.h>
#include <limits.h>
#include <memory.h>
#include <algorithm>

#define Left(a) ((a - le + 10) % 10)
#define Right(a) ((a + ri) % 10)
#define cst(a) (a / 3 + ((a % 3) ? 1 : 0))

using namespace std;

char a[107], b[107];

int dp[103][10][10][10];
int n;

int dy(int c, int x, int y, int z) {

	if (c == n)return 0;

	if (y < 0)y = 0;
	if (z < 0)z = 0;

	if (dp[c][x][y][z] != -1)return dp[c][x][y][z];

	int &ret = dp[c][x][y][z];

	ret = INT_MAX;

	int le = (x - (b[c] - '0') + 10) % 10;
	int ri = ((b[c] - '0') - x + 10) % 10;

	if (c + 2 < n) {
		ret = min(ret, min(cst(le) + dy(c + 1, Left(y), Left(z), a[c + 3] - '0'),
			cst(ri) + dy(c + 1, Right(y), Right(z), a[c + 3] - '0')));
	}
	if (c + 1 < n) {
		ret = min(ret, min(cst(le) + dy(c + 1, Left(y), z, a[c + 3] - '0'),
			cst(ri) + dy(c + 1, Right(y), z, a[c + 3] - '0')));
	}

	if (c < n) {
		int lr = min(le, ri);
		ret = min(ret, cst(lr) + dy(c + 1, y, z, a[c + 3] - '0'));
	}

	if (c + 2 < n) {
		for (int i = 0; i <= 9; i++) {
			le = ri = i;
			ret = min(ret, min(cst(le) + dy(c, Left(x), Left(y), Left(z)),
				cst(ri) + dy(c, Right(x), Right(y), Right(z))));
		}
	}

	if (c + 1 < n) {
		for (int i = 0; i <= 9; i++) {
			le = ri = i;
			ret = min(ret, min(cst(le) + dy(c, Left(x), Left(y), z),
				cst(ri) + dy(c, Right(x), Right(y), z)));
		}
	}


	return ret;

}

int main() {

	scanf("%d", &n);

	scanf("%s %s", a, b);

	memset(dp, 0xff, sizeof(dp));

	printf("%d\n", dy(0, a[0] - '0', a[1] - '0', a[2] - '0'));

}

/*
4
1952
2110

1952 =>
2952 =>
2152 =>
2130 =>
2110
*/