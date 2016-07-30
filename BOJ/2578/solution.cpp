#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

bool chk[7][7];

bool ended(int n) {

	int ret = 0;

	for (int i = 1; i <= n && ret < 3; i++) {
		bool wid = true, hei = true;
		for (int j = 1; j <= n; j++) {
			wid &= chk[i][j];
			hei &= chk[j][i];
		}
		ret += wid + hei;
	}

	bool dr = true, dl = true;

	for (int i = 1; i <= n; i++) {
		dr &= chk[i][i];
		dl &= chk[i][n + 1 - i];
	}

	return (ret + dr + dl) >= 3;

}

int main() {

	int n = 5;

	map < int, pair <int, int> > mp;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			int x;
			scanf("%d", &x);

			mp[x] = make_pair(i, j);
		}
	}

	int ans = 0;
	bool ends = false;

	for (int i = 1; i <= n*n; i++) {

		int x;
		scanf("%d", &x);

		if (ends)continue;

		chk[mp[x].first][mp[x].second] = true;

		ends = ended(n);

		ans = i;

	}

	printf("%d\n", ans);

}