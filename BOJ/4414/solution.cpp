#include <stdio.h>

#include <vector>

using namespace std;

#define ll long long

int main(){

	ll n, m;

	while(scanf("%lld %lld", &n, &m) == 2){

		if(!(n|m))break;
		
		if(n && m == 0){
			printf("%lld does not divide %lld!\n", m, n);
			continue;
		}

		printf("%lld ", m);

		vector <ll> p, c;

		for(ll i=2; i*i <= m; i++){

			if(m%i)continue;

			p.push_back(i);
			c.push_back(0);

			while(!(m%i)){
				m /= i;
				c.back()++;
			}

		}

		if(m != 1)p.push_back(m), c.push_back(1);

		bool flag = false;

		for(int i=0; i<p.size() && !flag; i++){


			ll k = p[i];

			while(k <= n){

				c[i] -= (n / k);

				k *= p[i];

			}

			if(c[i] > 0)flag = true;

		}

		if(flag)printf("does not divide ");
		else{
			printf("divides ");
		}

		printf("%lld!\n", n);

	}

}
