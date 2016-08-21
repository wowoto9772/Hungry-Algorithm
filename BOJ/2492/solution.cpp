#include <stdio.h>

#include <vector>

#include <algorithm>	

using namespace std;

#define x first
#define y second

pair <int, int> e[103];

int main()
{
	int n, m, t, k;
	scanf("%d %d %d %d", &n, &m, &t, &k);

	for (int i = 0; i < t; i++)scanf("%d %d", &e[i].x, &e[i].y);

	vector <int> xx, yy;

	for (int i = 0; i < t; i++) {
		xx.push_back(e[i].x);
		yy.push_back(e[i].y);
	}

	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());

	int ans = 0, p, q;

	for (int i = 0; i < xx.size(); i++) {

		int xl = xx[i];
		int xr = xl + k;

		for (int j = 0; j < yy.size(); j++) {

			int yl = yy[j];
			int yr = yl + k;

			int c = 0;

			for (int a = 0; a < t; a++) {
				if (xl <= e[a].x && e[a].x <= xr) {
					if (yl <= e[a].y && e[a].y <= yr) {
						c++;
					}
				}
			}

			if (ans < c) {
				ans = c;
				p = xl, q = min(yr, m);
			}
		}
	}

	if (p + k > n) {
		p -= (p + k - n);
	}

	printf("%d %d\n", p, q);
	printf("%d\n", ans);

}