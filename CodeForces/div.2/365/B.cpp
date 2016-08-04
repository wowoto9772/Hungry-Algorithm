#include <stdio.h>
#include <vector>

using namespace std;

#define ll long long

bool s[100003];
ll c[100003];

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

	long long Sum(int p) {
		long long ret = 0;
		while (p > 0) {
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};
