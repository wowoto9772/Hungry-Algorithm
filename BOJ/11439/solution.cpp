#include <stdio.h>
#include <vector>

#define ll long long

using namespace std;

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

long long modpower(long long a, long long p, long long m){
	
	long long r = 1;
	
	while(p){
		if(p&1)r = (r*a) % m;
		a = (a*a) % m;
		p >>= 1;
	}

	return r;
}

ll f[4000003] = {1,};

bool p[4000003];

void calc(vector <int> &p, vector <int> &c, int v, bool add){

	for(int i=0; i<p.size(); i++){

		ll j = p[i];

		while(j <= v){

			if(add)c[i] += v / j;
			else
				c[i] -= v / j;

			j *= p[i];

		}
		
	}

}

int main(){

	ll m;
	int n, k;

	scanf("%d %d %lld", &n, &k, &m);

	int l = n-k;


	vector <int> P, C;

	for(int i=2; i*i <= n; i++){
		if(!p[i]){
			for(int j=i*i; j<=n; j+=i)p[j] = true;
		}
	}

	for(int i=2; i<=n; i++){
		if(!p[i])P.push_back(i), C.push_back(0);
	}

	calc(P, C, n, true);
	calc(P, C, k, false);
	calc(P, C, l, false);

	ll ans = 1;

	for(int i=0; i<C.size(); i++){
		ans = (ans * modpower(P[i], C[i], m)) % m;
	}

	printf("%lld\n", ans);

}
