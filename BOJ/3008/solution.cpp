#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

#define x first
#define y second

using namespace std;

#define ll long long

pair <int, int> e[1503];

int gcd(int a, int b) {

	int m = 1;

	while (m) {
		m = a % b;
		a = b;
		b = m;
	}

	return a;

}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &e[i].x, &e[i].y);
	}

	int c = 0;

	for (int i = 0; i < n; i++) {

		multiset < pair <int, int> > cmp;
		vector < pair<int, int> > seg;

		for (int j = 0; j < n; j++) {

			if (i == j)continue;

			if (e[i].x == e[j].x) {
				seg.emplace_back(0, 1);
				cmp.emplace(1, 0);
			}
			else if (e[i].y == e[j].y) {
				seg.emplace_back(1, 0);
				cmp.emplace(0, 1);
			}
			else {

				int dx = e[i].x - e[j].x, dy = e[i].y - e[j].y;

				int g = gcd(abs(dx), abs(dy));

				dx /= g, dy /= g;

				if (dx < 0) {
					dx *= -1;
					dy *= -1;
				}

				seg.emplace_back(dx, dy);

				dy *= -1;

				if (dy < 0) {
					dy *= -1;
					dx *= -1;
				}

				cmp.emplace(dy, dx);

			}
		}

		for (int j = 0; j < seg.size(); j++)c += cmp.count(seg[j]);

	}

	printf("%d\n", c >> 1);

}