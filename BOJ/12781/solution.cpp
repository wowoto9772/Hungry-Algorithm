#include <stdio.h>
#define ll long long

class point {
public:
	int x, y;
};

int ccw(point &a, point &b, point &c) {
	ll dx1, dx2, dy1, dy2;
	dx1 = b.x - a.x;
	dy1 = b.y - a.y;
	dx2 = c.x - b.x;
	dy2 = c.y - b.y;

	ll ret = dx1*dy2 - dx2*dy1;
	if (ret < 0)return -1;
	else if (ret > 0)return 1;
	else
		return 0;
}

int main() {

	point x[2], y[2];

	for (int i = 0; i < 2; i++)scanf("%d %d", &x[i].x, &x[i].y);
	for (int i = 0; i < 2; i++)scanf("%d %d", &y[i].x, &y[i].y);

	if (ccw(x[0], x[1], y[0]) * ccw(x[0], x[1], y[1]) < 0) {
		if (ccw(y[0], y[1], x[0]) * ccw(y[0], y[1], x[1]) < 0) {
			printf("1\n");
			return 0;
		}
	}

	printf("0\n");

}