#include <stdio.h>

#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

class ele {
public:
	int x, y;
	bool operator<(const ele &A)const {
		if (x == A.x)return y < A.y;
		return x > A.x;
	}
}I[2000 * 1003];

class BIT {
public:
	vector <int> T;

	int S;

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

	ll Sum(int p) {
		ll ret = 0;
		while (p > 0) {
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};

int main() {

	ll ans = 0;

	int n, k;
	scanf("%d %d", &n, &k);

	BIT SX(n);
	BIT SY(n);

	for (int i = 0; i < k; i++) {
		scanf("%d %d", &I[i].x, &I[i].y);
		SX.Update(I[i].x, 1);
		SY.Update(I[i].y, 1);
	}

	sort(I, I + k);

	for (int i = k - 1; i >= 0; i--) {
		SX.Update(I[i].x, -1);
		SY.Update(I[i].y, -1);

		ll tot = SX.Sum(I[i].x); // count that X less than or equal to I[i].x

		tot += SY.Sum(n) - SY.Sum(I[i].y - 1); // count that Y greater than or equal to I[i].y

		ans += i - tot;
	}

	printf("%lld\n", ans);
}