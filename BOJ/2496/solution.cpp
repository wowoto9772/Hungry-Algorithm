#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main() {

	int t, k;
	scanf("%*d %*d %d %d", &t, &k);

	k >>= 1;

	vector < pair<int, int> > sexy(t);

	for (int i = 0; i < t; i++) {

		scanf("%d %d", &sexy[i].first, &sexy[i].second);

	}

	int ans = 0, xx, yy;

	set <int> mx, my;

	for (int i = 0; i < t; i++) {

		mx.insert(sexy[i].first);
		my.insert(sexy[i].second);

		for (int j = 0; j < t; j++) {

			if (i == j)continue;

			int a = sexy[i].first, b = sexy[i].second;
			int c = sexy[j].first, d = sexy[j].second;

			int _2x = d + c + a - b;
			int _2y = _2x - 2 * a + 2 * b;

			vector <int> x, y;

			int _x = _2x / 2;
			x.push_back(_x);

			if (_2x % 2) {
				x.push_back(_x - 1);
				x.push_back(_x + 1);
			}

			int _y = _2y / 2;
			y.push_back(_y);
			if (_2y % 2) {
				y.push_back(_y - 1);
				y.push_back(_y + 1);
			}

			for (int a = 0; a < x.size(); a++) {
				for (int b = 0; b < y.size(); b++) {
					for (int c = 0; c < 4; c++) {
						int cx = x[a] + dr[c] * k;
						int cy = y[b] + dc[c] * k;

						int tmp = 0;

						for (int w = 0; w < t; w++) {

							int cst = abs(sexy[w].first - cx) + abs(sexy[w].second - cy);
							if (cst <= k)tmp++;

						}

						if (tmp > ans) {
							ans = tmp;
							xx = cx, yy = cy;
						}

					}
				}
			}
		}
	}

	for (auto &cx : mx) {
		for (auto &cy : my) {

			int tmp = 0;

			for (int w = 0; w < t; w++) {

				int cst = abs(sexy[w].first - cx) + abs(sexy[w].second - cy);

				if (cst <= k)tmp++;

			}

			if (tmp > ans) {
				ans = tmp;
				xx = cx, yy = cy;
			}

		}
	}

	printf("%d %d\n", xx, yy);
	printf("%d\n", ans);

}