#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int bx[2], by[2], tx[2], ty[2];

		vector <int> x, y;

		for (int i = 0; i < 2; i++) {

			scanf("%d %d %d %d", &bx[i], &by[i], &tx[i], &ty[i]);

			x.push_back(bx[i]);
			x.push_back(tx[i]);

			y.push_back(by[i]);
			y.push_back(ty[i]);

		}

		sort(x.begin(), x.end());

		sort(y.begin(), y.end());

		int ans = 0;

		for (int i = 0; i < x.size() - 1; i++) {
			if (x[i] == x[i + 1])continue;
			for (int j = 0; j < y.size() - 1; j++) {
				if (y[i] == y[i + 1])continue;

				int f = 0;

				for (int k = 0; k < 2; k++) {

					if (bx[k] <= x[i] && x[i + 1] <= tx[k]) {
						if (by[k] <= y[j] && y[j + 1] <= ty[k]) {
							f |= 1<<k;
						}
					}

				}

				if (f == 1)ans += (x[i] - x[i + 1]) * (y[j] - y[j + 1]);

			}
		}

		printf("%d\n", ans);

	}

}