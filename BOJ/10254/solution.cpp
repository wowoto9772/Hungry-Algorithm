#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

class point{
public:
	int x, y;
	bool operator<(const point &A)const{
		if (x == A.x)return y < A.y;
		return x < A.x;
	}
};

ll dist(point &a, point &b){
	ll l = (a.x - b.x);
	l *= l;
	ll r = (a.y - b.y);
	r *= r;
	return  l + r;
}

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

point node[200003], up[200003], down[200003];
point cv[200003];
int n;

int convex_hull() {
	int iup, idown;
	idown = iup = -1;

	sort(node, node + n);

	int cnt;

	for (int i = 0; i < n; i++) {
		while (iup>0 && ccw(up[iup - 1], up[iup], node[i]) >= 0)iup--;
		up[++iup] = node[i];
		while (idown > 0 && ccw(down[idown - 1], down[idown], node[i]) <= 0)idown--;
		down[++idown] = node[i];
	}


	for (cnt = 0; cnt <= iup; cnt++) {
		cv[cnt] = up[cnt];
	}
	for (int i = idown - 1; i >= 0; i--) {
		cv[cnt++] = down[i];
	}

	return cnt; // convex hull's size
}

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d", &n);

		for (int i = 0; i < n; i++){
			scanf("%lld %lld", &node[i].x, &node[i].y);
		}

		int top = convex_hull();
		ll max = 0;
		int a = 0, b = 0;

		int e = 0;
		for (int s = 0; s < top; s++){
			while (dist(cv[s], cv[e]) < dist(cv[s], cv[(e + 1) % top])){
				e = (e + 1) % top;
			}

			ll tmax = dist(cv[s], cv[e]);
			if (max < tmax){
				max = tmax;
				a = s, b = e;
			}

		}

		printf("%d %d %d %d\n", cv[a].x, cv[a].y, cv[b].x, cv[b].y);
	}
}