#include <stdio.h>

#include <vector>

#include <algorithm>

using namespace std;

#define x first
#define y second

int main() {

	int n = 3;

	vector < pair <int, int> > v(n);

	for (int i = 0; i < n; i++)scanf("%d %d", &v[i].x, &v[i].y);

	sort(v.begin(), v.end());

	if (v[1].x - v[0].x == v[2].x - v[1].x) {
		if (v[1].y - v[0].y == v[2].y - v[1].y) {
			printf("%.10lf\n", -1.0);
			return 0;
		}
	}

	double maxi = -1.0, mini = 987654321.0;

	while (true) {

		int dx = v[1].x - v[0].x;
		int dy = v[1].y - v[0].y;

		vector < pair <int, int> > t = v;

		t.emplace_back(v.back().x + dx, v.back().y + dy);

		dx = t[0].x - t[2].x;
		dy = t[0].y - t[2].y;

		if (fabs(t[1].x - t[3].x - dx) <= 1e-10 && fabs(t[1].y - t[3].y - dy) <= 1e-10) {

			double w = sqrt((t[0].x - t[1].x)*(t[0].x - t[1].x) + (t[0].y - t[1].y)*(t[0].y - t[1].y));
			double h = sqrt((t[0].x - t[2].x)*(t[0].x - t[2].x) + (t[0].y - t[2].y)*(t[0].y - t[2].y));

			if (maxi < w + h)maxi = w + h;
			if (mini > w + h)mini = w + h;

		}

		if (!next_permutation(v.begin(), v.end()))break;

	}

	if (maxi < 0)printf("%.10lf\n", -1.0);
	else {
		printf("%.10lf\n", 2.0 * (maxi - mini));
	}

}