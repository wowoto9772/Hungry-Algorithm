#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

class ele {
public:
	int y; // y segment
	int mx, my;
	bool operator<(const ele &A)const {
		if (mx == A.mx) {
			if (my == A.my)return y < A.y;
			return my < A.my;
		}
		return mx < A.mx;
	}
}S[1000003];

int Y[500000];

class DAT {
public:
	long long x, y;
	bool operator<(const DAT &B)const {
		if (x == B.x)return y < B.y;
		return x < B.x;
	}
}I[1003];

int x[10003] = { 0 };
int y[10003] = { 0 };

int ab(int a) { return a < -a ? -a : a; }

int GCD(int a, int b) {
	int mod = 1;
	while (mod) {
		mod = a % b;
		a = b;
		b = mod;
	}return a;
}

int main()
{
	for (int i = 4; i <= 1000; i++) {
		int k = i * (i - 1) / 2;
		Y[k] = i;
	}

	int T = 1, top = 0;

	int n;
	while (scanf("%d", &n) == 1 && n) {
		top = 0;

		for (int i = 0; i < n; i++)scanf("%d %d", &I[i].x, &I[i].y);

		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));

		sort(I, I + n);

		int ans = 0, a;

		for (int i = 0; i < n; i++) {
			x[I[i].x]++, y[I[i].y]++;
			for (int j = i + 1; j < n; j++) {
				if (I[i].y != I[j].y && I[i].x != I[j].x) {
					int ax = I[i].x - I[j].x;
					int ay = I[i].y - I[j].y;

					int k = GCD(abs(ax), abs(ay));

					ax /= k, ay /= k;

					if (ax < 0) {
						ax *= -1, ay *= -1;
					}


					S[top].mx = ax, S[top].my = ay;

					S[top].y = ax * I[i].y - ay * I[i].x;

					top++;
				}
			}
		}

		sort(S, S + top);

		for (int i = 0; i <= 10000; i++) {
			if (y[i])ans = ans < y[i] ? y[i] : ans;
			if (x[i])ans = ans < x[i] ? x[i] : ans;
		}
		if (ans < 4)ans = 0;

		int ans2 = 0;

		for (int i = 0; i < top; i++) {
			int c = 1;
			int p = i;
			for (int j = i + 1; j < top; j++) {
				if (S[i].mx == S[j].mx && S[i].my == S[j].my && S[i].y == S[j].y) {
					c++;
					p = j;
				}
				else {
					i = j - 1;
					break;
				}
			}
			i = p;
			ans2 = ans2 < c ? c : ans2;
		}

		ans2 = Y[ans2];

		ans = ans < ans2 ? ans2 : ans;

		printf("Photo %d: %d points eliminated\n", T++, ans);
	}
}