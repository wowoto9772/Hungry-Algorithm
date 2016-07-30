#include <stdio.h>
#include <algorithm>

#define ll long long

using namespace std;

class dat {
public:
	int i, v;
}a[100003], b[100003], c[100003];

bool cmp(const dat &a, const dat &b) {
	return a.v < b.v;
}

class ele {
public:

	int a, b;
	ll c;

	ele() {}
	ele(int a_, int b_, ll c_) {
		a = a_, b = b_, c = c_;
	}

	bool operator<(const ele &A)const {
		return c < A.c;
	}

}I[300003];

int p[100003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &a[i].v, &b[i].v, &c[i].v);
		a[i].i = b[i].i = c[i].i = i;
	}

	sort(a + 1, a + 1 + n, cmp);
	sort(b + 1, b + 1 + n, cmp);
	sort(c + 1, c + 1 + n, cmp);

	int top = 0;

	for (int i = 1; i < n; i++) {
		I[top++] = ele(a[i].i, a[i + 1].i, abs(a[i].v - a[i + 1].v));
		I[top++] = ele(b[i].i, b[i + 1].i, abs(b[i].v - b[i + 1].v));
		I[top++] = ele(c[i].i, c[i + 1].i, abs(c[i].v - c[i + 1].v));
	}

	sort(I, I + top);

	ll ans = 0;

	for (int i = 0; i < top; i++) {
		int a = I[i].a, b = I[i].b;

		while (p[a])a = p[a];
		while (p[b])b = p[b];

		int pa = a, pb = b;

		a = I[i].a, b = I[i].b;

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

		if (pa != pb) {
			p[pa] = pb;
			ans += I[i].c;
		}
	}

	printf("%lld\n", ans);

}