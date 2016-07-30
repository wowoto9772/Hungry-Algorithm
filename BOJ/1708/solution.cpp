#include <stdio.h>
#include <algorithm>

using namespace std;

class point{
public:
	int x, y;
	bool operator<(const point &A)const{
		if (x == A.x)return y < A.y;
		return x < A.x;
	}
}node[100003];

long long ccw(point &a, point &b, point &c) {
	long long dx1, dx2, dy1, dy2;
	dx1 = b.x - a.x;
	dy1 = b.y - a.y;
	dx2 = c.x - b.x;
	dy2 = c.y - b.y;
	return dx1*dy2 - dx2*dy1;
}
point up[100003], down[100003];
point ch[200003];

int convex_hull(int n) {
	int iup, idown;
	idown = iup = -1;

	int cnt;

	for (int i = 0; i < n; i++) {
		while (iup>0 && ccw(up[iup - 1], up[iup], node[i]) >= 0)iup--;
		up[++iup] = node[i];
		while (idown>0 && ccw(down[idown - 1], down[idown], node[i]) <= 0)idown--;
		down[++idown] = node[i];
	}


	for (cnt = 0; cnt <= iup; cnt++) {
		ch[cnt] = up[cnt];
	}
	for (int i = idown - 1; i >= 0; i--) {
		ch[cnt++] = down[i];
	}

	return cnt-1;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d %d", &node[i].x, &node[i].y);
	sort(node, node + n);

	printf("%d\n", convex_hull(n));
}