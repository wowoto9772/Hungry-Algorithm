#include <stdio.h>
#include <vector>

using namespace std;

#define ll long long

class point{
public:
	ll x, y;
};

class line{
public:
	point s, e;
};

ll m(ll a, ll b){ return a < b ? a : b; }
ll M(ll a, ll b){ return a < b ? b : a; }
ll A(ll a){ return a < -a ? -a : a; }

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

point intersect(line &a, line &s){
	point ret;
	int x = 0, y = 0;
	if (s.s.x == s.e.x){ // 세로
		ret.x = s.e.x;
		x++;
	}
	else{ // 가로
		ret.y = s.e.y;
		y++;
	}

	if (a.s.x == a.e.x){ // 세로
		ret.x = a.s.x;
		x++;
	}
	else{ // 가로
		ret.y = a.s.y;
		y++;
	}

	return ret;
} // complete

int main(){

	ll L, Q;
	while (scanf("%lld %lld", &L, &Q) == 2){

		int dir = 0;

		vector <line> seg;

		line X;
		X.s = { -L - 1, -L - 1 };
		X.e = { -L - 1, L + 1 };
		seg.push_back(X);
		X.s = { -L - 1, -L - 1 };
		X.e = { L + 1, -L - 1 };
		seg.push_back(X);
		X.s = { L + 1, -L - 1 };
		X.e = { L + 1, L + 1 };
		seg.push_back(X);
		X.s = { -L - 1, L + 1 };
		X.e = { L + 1, L + 1 };
		seg.push_back(X);

		ll px = 0, py = 0;

		ll ans = 0;

		bool end = false;

		for (int i = 1; i <= Q + 1; i++){
			ll l;
			char t;

			if (i <= Q)scanf(" %lld %c", &l, &t);
			else{
				t = 'L';
				l = 3LL * L;
			}
			if (end)continue;

			ll x = px, y = py;

			if (dir == 0){ // 오른쪽(0)
				x += l;
			}
			else if (dir == 1){ // 위쪽(1)
				y += l;
			}
			else if (dir == 2){ // 왼쪽(2)
				x -= l;
			}
			else{ // 아래쪽(3)
				y -= l;
			}

			X.s = { px, py };
			X.e = { x, y };
			seg.push_back(X);

			ll min = 1000000000000000LL;



			int top = seg.size() - 1;

			for (int j = 0; j < seg.size() - 2; j++){
				int a = ccw(seg[top].s, seg[top].e, seg[j].s);
				int b = ccw(seg[top].s, seg[top].e, seg[j].e);
				int c = ccw(seg[j].s, seg[j].e, seg[top].s);
				int d = ccw(seg[j].s, seg[j].e, seg[top].e);
				if (c * d > 0)continue; // never meet
				else if (a * b > 0)continue; // never meet
				else{ // possible meet
					if (!a && !b && !c && !d){ // same line
						if (seg[top].s.x == seg[top].e.x){ // 세로'
							if (M(seg[top].s.y, seg[top].e.y) < m(seg[j].s.y, seg[j].e.y) || M(seg[j].s.y, seg[j].e.y) < m(seg[top].s.y, seg[top].e.y)){
								continue;
							}
							ll dist = m(A(seg[j].s.y - seg[top].s.y), A(seg[j].e.y - seg[top].s.y));
							if (dist <= l){ // meet
								min = m(min, dist);
							}
						}
						else{ // 가로
							if (M(seg[top].s.x, seg[top].e.x) < m(seg[j].s.x, seg[j].e.x) || M(seg[j].s.x, seg[j].e.x) < m(seg[top].s.x, seg[top].e.x)){
								continue;
							}
							ll dist = m(A(seg[j].s.x - seg[top].s.x), A(seg[j].e.x - seg[top].s.x));
							if (dist <= l){ // meet
								min = m(min, dist);
							}
						}
					}
					else{ // two line vertical & must meet
						point mt = intersect(seg[top], seg[j]);
						min = m(min, A(seg[top].s.x - mt.x) + A(seg[top].s.y - mt.y));
					}
				}
			}

			if (min == 1000000000000000LL){
				ans += l;
			}
			else{
				ans += min;
				end = true;
				continue;
			}

			if (dir == 0){ // 오른쪽(0)
				if (t == 'L')dir = 1;
				else{
					dir = 3;
				}
			}
			else if (dir == 1){ // 위쪽(1)
				if (t == 'L')dir = 2;
				else{
					dir = 0;
				}
			}
			else if (dir == 2){ // 왼쪽(2)
				if (t == 'L')dir = 3;
				else
					dir = 1;
			}
			else{ // 아래쪽(3)
				if (t == 'L')dir = 0;
				else
					dir = 2;
			}

			px = x, py = y;
		}

		printf("%lld\n", ans);
	}
}

