#include <stdio.h>
#define ll long long

ll gcd(ll a, ll b){
	ll m = 1;

	while (m){
		m = a % b;
		a = b;
		b = m;
	}

	return a;
}

ll lcm(ll a, ll b){
	ll g = gcd(a, b);
	return a / g * b;
}

int c[20003];

bool used[20003];

int T(int s){
	int t = 0;
	if (used[s])return 0;
	int a = s;
	while (true){
		s = c[s];
		used[s] = true;
		t++;
		if (s == a)return t;
	}
}

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
	}

	ll ans = 1;
	for (int i = 1; i <= n; i++){
		int f = T(i);
		if(f)ans = lcm(ans, f);
	}

	printf("%lld\n", ans);

}