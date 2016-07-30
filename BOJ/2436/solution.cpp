#include <stdio.h>
#include <vector>

using namespace std;

#define ll long long

int main(){

	ll g, l;
	scanf("%lld %lld", &g, &l);

	// lcm = a * b / gcd
	// a * b = lcm * gcd

	ll ab = g*l;
	ll a_b_ = ab / (g * g);

	ll ca_b_ = a_b_;

	vector <ll> p;
	for (ll i = 2; i*i <= a_b_; i++){

		ll c = 1;
		while (!(a_b_%i)){
			c *= i;
			a_b_ /= i;
		}

		if (c != 1)p.push_back(c);
	}

	if (a_b_ != 1)p.push_back(a_b_);

	int s = p.size();

	int min = 200000005, x, y;

	for (int i = 0; i < (1 << s); i++){

		ll c = 1;

		for (int j = 0; j < s; j++){
			if (i & (1 << j)){
				c *= p[j];
			}
		}

		ll a = g * c;
		ll b = g * (ca_b_ / c);

		if (a > b){
			ll tmp = a;
			a = b;
			b = tmp;
		}

		if (min > a + b){
			min = a + b;
			x = a, y = b;
		}
	}

	printf("%d %d\n", x, y);

}