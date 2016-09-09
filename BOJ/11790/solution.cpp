#include <stdio.h>

#include <limits.h>

#include <vector>

#include <algorithm>

using namespace std;

#define mod 1000000007LL
#define ll long long

#define HALF (10000000)
#define FULL (100000000000000L)

bool p[10000003];

vector < pair <ll, ll> > val;

vector < pair <ll, ll> > ans;

int main(){

	for(int i=2; i*i <= HALF; i++){
		if(!p[i]){
			for(int j=i*i; j<=HALF; j+=i)p[j] = true;
		}
	}

	for(ll i=2; i<=HALF; i++){
		if(!p[i]){
			for(ll j=i*i; j<=FULL; j*=i){
				val.emplace_back(j, i);
				if(j > FULL/i)break;
			}
		}
	}

	sort(val.begin(), val.end());

	ans.emplace_back(1LL, 1LL); // defaults

	for(int i=0; i<val.size(); i++){

		ans.emplace_back(val[i].first, (ans.back().second * (val[i].second % mod)) % mod);

	}

	int t;
	scanf("%d", &t);

	int tc = 0;

	while(t--){

		ll x;
		scanf("%lld", &x);

		int l = 0, r = ans.size()-1, m;

		int pans = 0;

		while(l <= r){
			
			m = (l+r) >> 1;

			if(ans[m].first <= x){
				pans = max(pans, m);
				l = m + 1;
			}else{
				r = m - 1;
			}

		}

		printf("Case %d: %lld\n", ++tc, ans[pans].second);

	}

}
