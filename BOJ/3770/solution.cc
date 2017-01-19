#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

class ele{
public:
	int x, y;
	bool operator<(const ele &A)const{
        if(x == A.x)return y < A.y;
        return x > A.x;
	}
}e[1000003];

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

	ll Sum(int p){
		ll ret = 0;
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

    int tc = 0;

    while(t--){
		ll ans = 0;

		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);

		BIT SX(n);
		BIT SY(m);

		for (int i = 0; i < k; i++){
			scanf("%d %d", &e[i].x, &e[i].y);
			SX.Update(e[i].x, 1);
			SY.Update(e[i].y, 1);
		}

		sort(e, e + k);

		for (int i = k-1; i >= 0; i--){
			SX.Update(e[i].x, -1);
			SY.Update(e[i].y, -1);
			int x = SX.Sum(e[i].x); // count that X less than or equal to e[i].x
			int y = SY.Sum(m) - SY.Sum(e[i].y - 1); // count that Y greater than or equal to e[i].y

			ans += i - (x+y); // count that X greater than e[i].x and Y less than e[i].y
		}

		printf("Test case %d: %lld\n", ++tc, ans);
	}
}
