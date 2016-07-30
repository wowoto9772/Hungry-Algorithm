#include <stdio.h>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {

	int m = 1;

	while (m) {
		m = a % b;
		a = b;
		b = m;
	}

	return a;

}

class ele {
public:

	int dx, dy;
	int y;

	ele() {}
	ele(int a, int b, int c) { dx = a, dy = b, y = c; }

	bool operator<(const ele &A)const {
		if (dx == A.dx) {
			if (dy == A.dy)return y < A.y;
			return dy < A.dy;
		}
		return dx < A.dx;
	}

	bool operator*(const ele &A)const {
		return dx == A.dx && dy == A.dy && y == A.y;
	}

}J[20003];

class point {
public:
	int x, y;
	bool operator<(const point &A)const {
		if (x == A.x)return y < A.y;
		return x < A.x;
	}
}I[203];

int par[20003];

int main() {

	int n;
	while (scanf("%d", &n) == 1) {

		if (n == 1)printf("1\n");
		else {

			for (int i = 0; i < n; i++) {
				scanf("%d %d", &I[i].x, &I[i].y);
			}

			for (int i = 2; i <= n; i++) {
				par[i*(i - 1) / 2] = i;
			}

			sort(I, I + n);

			int top = 0;

			// nC2 = (n-1)n/2
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (I[i].x == I[j].x) {
						J[top++] = ele(I[i].x, 0, 0);
					}
					else if (I[i].y == I[j].y) {
						J[top++] = ele(0, I[i].y, 0);
					}
					else {
						int dx = I[i].x - I[j].x, dy = I[i].y - I[j].y;
						int g = gcd(abs(dx), abs(dy));

						dx /= g, dy /= g;

						if (dx < 0)dx *= -1, dy *= -1;

						// y = dy/dx * (x-x_0)+y_0
						// dx * y = dy * (x-x_0) + dx * y_0
						// dx * y = dy * (0-x_0) + dx * y_0

						J[top++] = ele(dx, dy, dx*I[j].y - dy*I[j].x);
					}
				}
			}

			sort(J, J + top);

			int c = 1, f = 0;

			int ans = 0;

			for (int i = 1; i < top; i++) {
				if (J[f] * J[i])c++;
				else {

					ans = max(ans, par[c]);

					f = i;
					c = 1;
				}
			}

			ans = max(ans, par[c]);

			printf("%d\n", ans);

		}

	}

}

//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//
//#define ll long long
//
//class point {
//public:
//	int x, y;
//	bool operator<(const point &A)const {
//		if (x == A.x)return y < A.y;
//		return x < A.x;
//	}
//}I[203];
//
//int ccw(point &a, point &b, point &c) {
//	ll dx1, dx2, dy1, dy2;
//	dx1 = b.x - a.x;
//	dy1 = b.y - a.y;
//	dx2 = c.x - b.x;
//	dy2 = c.y - b.y;
//
//	ll ret = dx1*dy2 - dx2*dy1;
//	if (ret < 0)return -1;
//	else if (ret > 0)return 1;
//	else
//		return 0;
//}
//
//int main() {
//
//	int n;
//	scanf("%d", &n);
//
//	if (n == 1)printf("1\n");
//	else {
//
//		for (int i = 0; i < n; i++) {
//			scanf("%d %d", &I[i].x, &I[i].y);
//		}
//
//		int ans = 0;
//
//		for (int i = 0; i < n; i++) {
//			for (int j = i + 1; j < n; j++) {
//				int c = 2;
//				for (int k = 0; k < n; k++) {
//					if (i == k || k == j)continue;
//					if (!ccw(I[i], I[j], I[k]))c++;
//				}
//				ans = max(ans, c);
//			}
//		}
//
//		printf("%d\n", ans);
//
//	}
//
//}