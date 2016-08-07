#include <stdio.h>
#include <algorithm>

using namespace std;

class ele {
public:

	int id, sub, pts, lst;

	ele() {}
	ele(int _id, int _sub, int _pts, int _lst) {
		id = _id, sub=_sub, pts = _pts, lst = _lst;
	}

	bool operator<(const ele &A)const {
		if (pts == A.pts) {
			if(sub == A.sub)return lst < A.lst;
			return sub < A.sub;
		}
		return pts > A.pts;
	}

}dat[103];

int pts[103][103];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n, k, x, m;
		scanf("%d %d %d %d", &n, &k, &x, &m);

		for (int i = 1; i <= n; i++) {
			dat[i] = { i, 0, 0, 0 };
		}

		for (int i = 1; i <= n; i++)for (int j = 1; j <= k; j++)pts[i][j] = 0;

		int tt = 0;

		while (m--) {

			int i, j, s;
			scanf("%d %d %d", &i, &j, &s);

			dat[i].lst = ++tt;
			dat[i].sub++;

			if (pts[i][j] < s) {
				dat[i].pts += s - pts[i][j];
				pts[i][j] = s;
			}

		}

		sort(dat + 1, dat + 1 + n);

		for (int i = 1; i <= n; i++) {
			if (dat[i].id == x) {
				printf("%d\n", i);
			}
		}

	}

}