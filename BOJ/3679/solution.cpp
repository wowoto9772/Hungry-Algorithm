#include <stdio.h>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

class point {
public:

	ll x, y;
	int i;

	double seta;

	point() {}
	point(ll x_, ll y_) {
		x = x_, y = y_;
	}

	bool operator<(const point &A)const {
		return seta < A.seta;
	}
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

class Polygon {
public:

	int n;

	vector <point> e;

	Polygon(int n_) {

		n = n_;
		e.resize(n);

		double midx = 0.0, midy = 0.0;

		for (int i = 0; i < n; i++) {
			scanf("%lld %lld", &e[i].x, &e[i].y);
			midx += e[i].x;
			midy += e[i].y;
			e[i].i = i;
		}

		midx /= n;
		midy /= n;

		for (int i = 0; i < n; i++) {
			e[i].seta = atan2(e[i].x - midx, e[i].y - midy);
		}
	}


	void make_polygon() {

		sort(e.begin(), e.end());

	}
};

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		Polygon my(n);

		my.make_polygon();

		for (int i = 0; i < n; i++) {
			printf("%d ", my.e[i].i);
		}

		printf("\n");

	}

}