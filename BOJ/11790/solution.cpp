#include <stdio.h>

#define ll long long
#define mod 1000000007LL

/* Find a^p mod m */
long long modpower(long long a, long long p, long long m){

	long long r = 1;

	while(p){
		if(p&1)r = (r*a) % m;
		a = (a*a) % m;
		p >>= 1;
	}

	return r;
}

bool p[10000003];
ll P[2000003];

int top;

int main(){

	for(int i=2; i*i <= 10000000; i++){
		if(!p[i]){
			for(int j=i*i; j<=10000000; j+=i)p[j] = true;
		}
	}

	for(int i=2; i<=10000000; i++){
		if(!p[i])P[top++] = i;
	}

	int t;
	scanf("%d", &t);

	int tc = 0;

	while(t--){

		ll v;
		scanf("%lld", &v);

		printf("Case %d: ", ++tc);

		ll ans = 1;

		for(ll i=0; P[i]*P[i] <= v && i < top; i++){
			ll c = P[i];
			int m = 0;
			while(c <= v){
				m++;
				c *= P[i];
			}
			m--;
			ans *= modpower(P[i], m, mod);
			ans %= mod;
		}

		printf("%lld\n", ans);

	}

}
