#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
#define max(a, b) a < b ? b : a
#define min(a, b) a < b ? a : b

using namespace std;

class ele{
public:
	int x, v;
	bool operator<(const ele &A)const{
		if (v == A.v)return x < A.x;
		return v < A.v;
	}
}I[40002];

class BIT{
public:
	vector <ll> T;
	int S;
	BIT(const int &n){
		S = n;
		T.resize(S + 1);
	}
	void update(int p, int v){
		while (p <= S){
			T[p] += v;
			p += p & (-p);
		}
	}
	ll sum(int p){
		ll ret = 0;
		while (p){
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};

int main()
{
	int n;
	scanf("%d", &n);

	BIT tree(20001), cnt(20001);
	
	int R = 0, L = 20001;
	for (int i = 1; i <= n; i++){
		scanf("%d %d", &I[i].v, &I[i].x);
		tree.update(I[i].x, I[i].x);
		cnt.update(I[i].x, 1);
		R = max(R, I[i].x);
		L = min(L, I[i].x);
	}

	sort(I + 1, I + 1 + n);

	ll ans = 0;
	for (int i = n; i >= 1; i--){
		tree.update(I[i].x, -I[i].x);
		cnt.update(I[i].x, -1);
		ll l = tree.sum(R) - tree.sum(I[i].x);
		ll m = cnt.sum(R) - cnt.sum(I[i].x);
		l -= m * I[i].x;
		ans += l * I[i].v;
		l = tree.sum(I[i].x-1);
		m = cnt.sum(I[i].x-1);
		l =  m * I[i].x - l;
		ans += l * I[i].v;
	}

	printf("%lld\n", ans);
}