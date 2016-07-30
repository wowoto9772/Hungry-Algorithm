#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int gcd(int a, int b){
	int m = 1;
	while (m){
		m = a % b;
		a = b;
		b = m;
	}return a;
}

ll lcm(ll a, ll b){
	ll g = a / gcd(a, b);
	g *= b;
	return g;
}

ll what(ll a, ll b, ll p){
	ll ret = 1;
	while (!(a % p)){
		ret *= p;
		a /= p;
	}
	ll ret2 = 1;
	while (!(b%p)){
		ret2 *= p;
		b /= p;
	}
	return max(ret, ret2);
}

int main(){
	int a, b;
	ll L;
	scanf("%d %d %lld", &a, &b, &L);

	ll l = lcm(a, b);

	ll c;

	if (L%l)c = -1;
	else{
		c = L / l;

		vector <ll> p;

		ll cc = c;

		for (ll i = 2; i*i <= cc; i++){
			if (cc % i)continue;
			p.push_back(i);
			while (!(cc%i)){
				cc /= i;
			}
		}

		if (cc != 1)p.push_back(cc);

		for (int i = 0; i < p.size(); i++){
			c *= what(a, b, p[i]);
		}

	}

	printf("%lld\n", c);
}