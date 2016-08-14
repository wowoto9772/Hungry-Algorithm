#include <stdio.h>

#include <vector>
#include <algorithm>

#define ll long long
#define mod 1000000007LL

using namespace std;

class BIT_MULTY {
public:

	vector <ll> T;
	int S;

	BIT_MULTY(const int n) {

		S = n;
		T.resize(S + 1);

		for (int i = 1; i <= S; i++)T[i] = 1LL;

	}

	void Update(int p, ll v) {
		while (p <= S) {
			T[p] *= v;
			T[p] %= mod;
			p += p & (-p);
		}
	}

	long long Sum(int p) {
		if (p == 0)return 1;
		long long ret = 1;
		while (p > 0) {
			ret *= T[p];
			ret %= mod;
			p -= p & (-p);
		}return ret;
	}

};

class BIT_ADD {
public:

	vector <ll> T;
	int S;

	BIT_ADD(const int n) {

		S = n;
		T.resize(S + 1);

	}

	void Update(int p, ll v) {
		while (p <= S) {
			T[p] += v;
			p += p & (-p);
		}
	}

	long long Sum(int p) {
		if (p == 0)return 0;
		long long ret = 0;
		while (p > 0) {
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}

};

ll e[100003];

/* find a pair (c,d) s.t. ac + bd = gcd(a,b)
* Dependencies: none */
pair<long long, long long> extended_gcd(long long a, long long b) {
	if (b == 0) return make_pair(1, 0);
	pair<long long, long long> t = extended_gcd(b, a % b);
	return make_pair(t.second, t.first - t.second * (a / b));
}

/* Find x in [0,m) s.t. ax ≡ gcd(a, m) (mod m)
* Dependencies: extended_gcd(a, b) */
long long modinverse(long long a, long long m) {
	return (extended_gcd(a, m).first % m + m) % m;
}


int main() {

	int n, q, p;
	scanf("%d %d %d", &n, &q, &p);

	q += p;

	BIT_MULTY tree(n);
	BIT_ADD flag(n);

	for (int i = 1; i <= n; i++) {

		ll v;
		scanf("%lld", &v);

		if (v) {
			flag.Update(i, 1);
			tree.Update(i, v);
		}

		e[i] = v;

	}

	while (q--) {

		int x, l, r;
		scanf("%d %d %d", &x, &l, &r);

		if (x == 2) {

			if (l > r)swap(l, r);

			if (flag.Sum(r) - flag.Sum(l - 1) != r - l + 1)printf("0\n");
			else {
				ll tmp = (tree.Sum(r) * modinverse(tree.Sum(l - 1), mod)) % mod;
				printf("%lld\n", tmp);
			}

		}
		else {

			if (e[l]) {
				flag.Update(l, -1);
				tree.Update(l, modinverse(e[l], mod));
			}
			
			e[l] = r;

			if (e[l]) {
				flag.Update(l, 1);
				tree.Update(l, e[l]);
			}

		}

	}

}