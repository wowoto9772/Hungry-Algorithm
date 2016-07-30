#include <stdio.h>

#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class ele{
public:
	int x, y;
	bool operator<(const ele &A)const{
		if (x == A.x)return y < A.y;
		return x > A.x;
	}
}I[75003];

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

		int n;
		scanf("%d", &n);

		vector <int> xi, yi;
		for (int i = 1; i <= n; i++){
			scanf("%d %d", &I[i].x, &I[i].y);
			xi.push_back(I[i].x);
			yi.push_back(I[i].y);
		}

		sort(xi.begin(), xi.end());
		xi.resize(distance(xi.begin(), unique(xi.begin(), xi.end())));
		sort(yi.begin(), yi.end());
		yi.resize(distance(yi.begin(), unique(yi.begin(), yi.end())));

		BIT SX(xi.size());
		BIT SY(yi.size());

		for (int i = 1; i <= n; i++){
			int l = 0, r = xi.size() - 1, m;
			while (l <= r){
				m = (l + r) / 2;
				if (xi[m] == I[i].x){
					break;
				}
				else if (xi[m] < I[i].x){
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			SX.Update(m + 1, 1);
			l = 0, r = yi.size() - 1, m;
			while (l <= r){
				m = (l + r) / 2;
				if (yi[m] == I[i].y){
					break;
				}
				else if (yi[m] < I[i].y){
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			SY.Update(m + 1, 1);
		}

		sort(I + 1, I + 1 + n);

		for (int i = n; i >= 1; i--){
			int l = 0, r = xi.size() - 1, m;
			while (l <= r){
				m = (l + r) / 2;
				if (xi[m] == I[i].x){
					break;
				}
				else if (xi[m] < I[i].x){
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			SX.Update(m + 1, -1);
			int a = SX.Sum(xi.size()) - SX.Sum(m); // equal Big X
			l = 0, r = yi.size() - 1, m;
			while (l <= r){
				m = (l + r) / 2;
				if (yi[m] == I[i].y){
					break;
				}
				else if (yi[m] < I[i].y){
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			SY.Update(m + 1, -1);
			int b = SY.Sum(m + 1); // equal Small Y 

			ans += a+b - (i - 1); // A+B - (AUB) = A^B
		}

		printf("%lld\n", ans);
	}
}