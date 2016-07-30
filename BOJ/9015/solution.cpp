#include <stdio.h>

#include <set>
#include <algorithm>

#define x first
#define y second

using namespace std;

pair<int, int> p[3003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		set < pair<int, int> > ex;

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &p[i].x, &p[i].y);

			ex.insert(p[i]);
		}

		sort(p, p + n);

		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {

				int a = p[i].x + p[j].x;
				int b = p[i].y + p[j].y;
				int c = p[j].x - p[i].x;
				int d = p[j].y - p[i].y;

				if ((a + b) & 1)continue; // only integer

				pair <int, int> g = { (a - d) / 2 , (b + c) / 2 };

				if (ex.find(g) != ex.end()) {

					g = { (a + d) / 2, (b - c) / 2 };

					if (ex.find(g) != ex.end()) {

						ans = max(ans, (c*c + d*d));

					}

				}
			}
		}

		printf("%d\n", ans >> 1);

	}

}