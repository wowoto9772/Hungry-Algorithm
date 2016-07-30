#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <algorithm>

using namespace std;

class point {
public:
	int x, y;
	point() {}
	point(int a, int b) { x = a, y = b; }

	int operator ^(const point &A) {
		return (x - A.x)*(x - A.x) + (y - A.y)*(y - A.y);
	}
}red[13], blue[13];

int ccw(point &a, point &b, point &c) {

	int dx1, dx2, dy1, dy2;

	dx1 = b.x - a.x;
	dy1 = b.y - a.y;
	dx2 = c.x - b.x;
	dy2 = c.y - b.y;

	int ret = dx1*dy2 - dx2*dy1;

	if (ret < 0)return -1;
	else if (ret > 0)return 1;
	else
		return 0;
}

int n;
int m[13];
int ans;

int fuck() {

	int len = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ccw(red[i], blue[m[i]], red[j]) * ccw(red[i], blue[m[i]], blue[m[j]]) < 0
				&& ccw(red[j], blue[m[j]], red[i]) * ccw(red[j], blue[m[j]], blue[m[i]]) < 0) {
				// intersects.
				return -1;
			}
		}

		len = max(len, red[i] ^ blue[m[i]]);
		if (ans < len)return -1;
	}

	return len;

}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &red[i].x, &red[i].y);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &blue[i].x, &blue[i].y);
	}

	for (int i = 0; i < n; i++)m[i] = i;

	ans = INT_MAX;

	while (true) {
		int you = fuck();
		if (you != -1)ans = min(ans, you);

		int g = next_permutation(m, m + n);
		if (!g)break;
	}

	if (ans == INT_MAX)printf("-1\n");
	else {
		printf("%.3lf\n", sqrt((double)ans));
	}

}