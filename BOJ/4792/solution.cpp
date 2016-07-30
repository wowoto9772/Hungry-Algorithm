#include <stdio.h>
#include <algorithm>

using namespace std;

class ele {
public:
	ele() {}
	ele(int a_, int b_, int c_) { a = a_, b = b_, c = c_; }
	int a, b, c;
	bool operator<(const ele &A)const {
		return c < A.c;
	}
}e[1003 * 1003];

int n, m;
int p[1003];

int mst(int st, int ar, int x) {

	int ret = 0;

	for (int i = 1; i <= n; i++)p[i] = 0;

	for (int i = st; i != ar; i+=x) {

		int a = e[i].a, b = e[i].b;

		while (p[a])a = p[a];
		while (p[b])b = p[b];

		int pa = a, pb = b;

		a = e[i].a, b = e[i].b;

		while (p[a]) {
			int t = p[a];
			p[a] = pa;
			a = t;
		}

		while (p[b]) {
			int t = p[b];
			p[b] = pb;
			b = t;
		}

		if (a == b)continue;

		p[a] = b;
		ret += e[i].c;

	}

	return ret;

}

int main() {

	int k;
	while (scanf("%d %d %d", &n, &m, &k) == 3) {

		if (!n && !m && !k)break;

		int top = 0;

		for (int i = 0; i < m; i++) {

			char t;
			int a, b;

			scanf(" %c %d %d", &t, &a, &b);

			e[i] = { a, b, t == 'B' };
		}

		sort(e, e + m);

		int le = mst(0, m, 1);

		int ri = mst(m - 1, 0, -1);

		if (le <= k && k <= ri)printf("1\n");
		else
			printf("0\n");
	}

}