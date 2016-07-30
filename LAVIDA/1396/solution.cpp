/*
	1
	3 4 5
	3 1
	3 2
	2 1
	2 3
	1 4
*/

#include <stdio.h>

#include <vector>
#include <algorithm>

using namespace std;

class ele{
public:
	int x, y;
	bool operator<(const ele &A)const{
		if (x == A.x)return y < A.y;
		return x > A.x;
	}
}I[1000003];

class BIT{
public:
	vector <int> T;
	int S;
	BIT(const int n){
		S = n;
		T.resize(S + 1);
	}
	void Update(int p, int v){
		while (p <= S){
			T[p] += v;
			p += p & (-p);
		}
	}
	long long Sum(int p){
		long long ret = 0;
		while (p > 0){
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};

int main()
{
	int t;
	scanf("%d", &t);

	for (int T = 1; T <= t; T++){
		long long ans = 0;

		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);

		BIT SX(n);
		BIT SY(m);

		for (int i = 0; i < k; i++){
			scanf("%d %d", &I[i].x, &I[i].y);
			SX.Update(I[i].x, 1);
			SY.Update(I[i].y, 1);
		}

		sort(I, I + k);

		for (int i = k - 1; i >= 0; i--){
			SX.Update(I[i].x, -1);
			SY.Update(I[i].y, -1);
			int tot = SX.Sum(I[i].x); // count that X less than or equal to I[i].x
			tot += SY.Sum(m) - SY.Sum(I[i].y - 1); // count that Y greater than or equal to I[i].y

			ans += i - tot; // (A+B) - (AUB) = A^B
		}

		printf("Test case %d: %lld\n", T, ans);
	}
}