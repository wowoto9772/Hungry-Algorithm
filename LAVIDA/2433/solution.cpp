#include <stdio.h>
#include <algorithm>
#define mod 1000000007
#define ll long long

using namespace std;

class ele{
public:
	int u, v, c;
	bool operator<(const ele &A)const{
		return c < A.c;
	}
}I[100003];

int p[100003], s[100003];

ll pow2(int a){
	ll ret = 1;
	ll two = 2;
	while (a){
		if (a & 1)ret = ret * two % mod;
		a >>= 1LL;
		two = (two * two) % mod;
	}return ret;
}

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++){
		scanf("%d %d %d", &I[i].u, &I[i].v, &I[i].c);
		s[i + 1] = 1;
	}s[n] = 1;

	sort(I, I + n - 1);

	long long ans = 0;

	for (int i = n-2; i >= 0; i--){
		int u = I[i].u, v = I[i].v;
		while (p[u])u = p[u];
		while (p[v])v = p[v];
		int su = u, sv = v;
		u = I[i].u, v = I[i].v;
		while (p[u]){
			p[u] = su;
			u = p[u];
		}
		while (p[v]){
			p[v] = sv;
			v = p[v];
		}

		ll x = (pow2(s[u]) - 1) * (pow2(s[v]) - 1);
		x %= mod;
		x *= I[i].c;
		x %= mod;

		ans += x;
		ans %= mod;

		s[v] += s[u];
		p[u] = v;
	}

	printf("%lld\n", ans);

}