#include <stdio.h>
#include <math.h>

#include <vector>
#include <queue>

#include <algorithm>

#define ll long long

using namespace std;

ll gcd(ll a, ll b){
	ll m = 1;
	while (m){
		m = a % b;
		a = b;
		b = m;
	}return a;
}

int main(){

	int n;
	scanf("%d", &n);

	ll a;
	scanf("%lld", &a);
	for (int i = 1; i < n; i++){
		ll b;
		scanf("%lld", &b);
		a = gcd(a, b);
	}

	vector <ll> p;
	vector <int> c;
	for (int i = 2; i*i <= a; i++){
		if (a%i)continue;
		p.push_back(i);
		c.push_back(1);
		a /= i;
		while (!(a%i)){
			a /= i;
			c.back()++;
		}
	}

	if (a != 1){
		p.push_back(a);
		c.push_back(1);
	}

	queue <ll> v;
	queue <int> x;
	v.push(1), x.push(0);

	vector <ll> ans;

	while (!v.empty()){

		ll V = v.front(); v.pop();
		int X = x.front(); x.pop();

		ans.push_back(V);

		for (int i = X; i < p.size(); i++){
			for (int j = 1; j <= c[i]; j++){
				ll Y = V * pow(p[i], j);
				v.push(Y);
				x.push(i + 1);
			}
		}

	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)printf("%lld\n", ans[i]);

}