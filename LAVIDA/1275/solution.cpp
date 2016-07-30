#include <stdio.h>
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

class convex{
public:
	int n = 0;
	point node[5003], up[5003], down[5003];
	point cv[5003];

	void input(){
		scanf("%d %d", &node[n].x, &node[n].y);
		n++;
	}

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
}X, Y;

int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a < b ? b : a; }

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		X.n = Y.n = 0;

		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			int a;
			scanf("%d", &a);
			if (a){
				X.input();
			}
			else{
				Y.input();
			}
		}

		int x = X.convex_hull();
		int y = Y.convex_hull();
		bool flag = false;

		for (int i = 0; !flag && i < y - 1; i++){
			for (int j = 0; !flag && j < x - 1; j++){
				int a = ccw(Y.cv[i], Y.cv[i + 1], X.cv[j]);
				int a2 = ccw(Y.cv[i], Y.cv[i + 1], X.cv[j + 1]);
				if (a*a2 < 0){
					int b = ccw(X.cv[j], X.cv[j + 1], Y.cv[i]);
					int b2 = ccw(X.cv[j], X.cv[j + 1], Y.cv[i + 1]);
					if (b*b2 < 0){
						flag = true; // completely meet one point
					}
				}
			}
		}

		for (int i = 0; !flag && i < Y.n; i++){
			int pl = 0, mi = 0;
			for (int j = 0; !flag && j < x - 1; j++){
				int stable = ccw(X.cv[j], X.cv[j + 1], Y.node[i]);
				if (!stable){
					int mx = min(X.cv[j].x, X.cv[j + 1].x);
					int Mx = max(X.cv[j].x, X.cv[j + 1].x);
					int my = min(X.cv[j].y, X.cv[j + 1].y);
					int My = max(X.cv[j].y, X.cv[j + 1].y);
					if (mx <= Y.node[i].x && Y.node[i].x <= Mx){
						if (my <= Y.node[i].y && Y.node[i].y <= My){
							flag = true;
						}
					}
				}
				else{
					if (stable > 0){
						pl++;
					}
					else{
						mi++;
					}
				}
			}

			if (!pl || !mi){
				flag = true; // inbound check
			}
		}

		if (flag)printf("THEORY IS INVALID\n");
		else{
			printf("THEORY HOLDS\n");
		}
	}
}

/*
100
8
1 0 0
1 0 4
1 4 4
1 4 0
0 1 1
0 1 3
0 3 3
0 3 1
*/