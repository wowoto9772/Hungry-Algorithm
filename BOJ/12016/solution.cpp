#include <stdio.h>
#include <queue>
#include <vector>
#define ll long long

using namespace std;

class BIT {
public:
	vector <int> T;
	int S;

	BIT() {}

	BIT(const int n) {
		S = n;
		T.resize(S + 1);
	}
	void Update(int p, int v) {
		while (p <= S) {
			T[p] += v;
			p += p & (-p);
		}
	}
	int Sum(int p) {
		long long ret = 0;
		while (p > 0) {
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};

class ele {
public:
	ele() {}
	ele(int a, int b) { i = a, v = b; }
	int i, v;
	bool operator<(const ele &A)const {
		if (v == A.v)return i > A.i;
		return v > A.v;
	}
};

ll fin[100003];

int main() {

	int n;
	scanf("%d", &n);

	BIT tree(n);
	priority_queue <ele> q;
	for (int i = 1; i <= n; i++) {

		int v;
		scanf("%d", &v);

		q.emplace(i, v);
		tree.Update(i, 1);

	}

	ll t = 0;
	int p = n + 1;
	int c = 0;

	while (!q.empty()) {

		ele f = q.top(); q.pop();

		if (c < f.v) {
			int s = tree.Sum(n);

			ll nt;
			nt = t + tree.Sum(n) - tree.Sum(p - 1) + tree.Sum(f.i) + (ll)(f.v - c - 1) * s;
			t = nt;

			fin[f.i] = t;
			tree.Update(f.i, -1);

			p = f.i;

			c = f.v;
		}
		else {
			ll nt = t + tree.Sum(f.i) - tree.Sum(p);
			t = nt;
			fin[f.i] = t;
			tree.Update(f.i, -1);
			p = f.i;
		}

	}

	for (int i = 1; i <= n; i++)printf("%lld\n", fin[i]);

}