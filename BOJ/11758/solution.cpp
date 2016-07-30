#include <stdio.h>
#define ll long long

struct point{
	ll x, y;
	point(ll x = 0, ll y = 0) :x(x), y(y){}
	bool operator<(const point &A)const{
		if (x == A.x)return y < A.y;
		return x < A.x;
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

int main(){
	point a, b, c;
	scanf("%lld %lld", &a.x, &a.y);
	scanf("%lld %lld", &b.x, &b.y);
	scanf("%lld %lld", &c.x, &c.y);

	printf("%d\n", ccw(a, b, c));
}