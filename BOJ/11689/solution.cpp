#include <stdio.h>
#include <vector>
#include <queue>

#include <algorithm>

#define ll long long

using namespace std;

int main(){

	ll n, cn;
	scanf("%lld", &n);

	cn = n;

	vector <ll> v;

	for (ll i = 2; i*i <= n; i++){
		if (n%i)continue;
		else{
			while (!(n%i))n /= i;
			v.push_back(i);
		}
	}

	if (n != 1)v.push_back(n);

	n = cn;

	sort(v.begin(), v.end());

	queue <ll> q;
	queue <int> p;
	queue <bool> c;

	for (int i = 0; i < v.size(); i++){
		q.push(v[i]);
		p.push(i);
		c.push(true);
	}

	ll ans = n;

	while (!q.empty()){
		ll m = q.front(); q.pop();
		bool flg = c.front(); c.pop();
		int s = p.front(); p.pop();

		if (flg){
			ans -= n / m;
		}
		else{
			ans += n / m;
		}

		for (int i = s + 1; i < v.size(); i++){
			ll nm = m * v[i];
			if (nm <= n){
				q.push(nm);
				c.push(!flg);
				p.push(i);
			}
			else{
				break;
			}
		}
	}

	printf("%lld\n", ans);
}