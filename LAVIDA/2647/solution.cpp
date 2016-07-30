// also have my java solution

// cpp solution
//#include <stdio.h>
//#define ll unsigned long long
//
//bool chk[77][77];
//ll dp[77][77][2];
//ll gcd(ll a, ll b){
//	ll mod = 1;
//	while (mod){
//		mod = a % b;
//		a = b;
//		b = mod;
//	}return a;
//}
//
//ll lcm(ll a, ll b){
//	ll g = gcd(a, b);
//	return a / g * b;
//}
//
//void P(ll r, ll w){ // probability (r, c)
//	if (chk[r][w])return;
//	chk[r][w] = true;
//
//	dp[r][w][1] = r + w;
//	dp[r][w][0] = r;
//
//	ll g;
//
//	if (w >= 2){
//		if (!chk[r][w - 2])P(r, w - 2);
//		ll c = w*(w - 1);
//		ll d = (r + w)*(r + w - 1);
//
//		g = gcd(c, d);
//		c /= g;
//		d /= g;
//
//		c *= dp[r][w - 2][0];
//		d *= dp[r][w - 2][1];
//
//		g = gcd(c, d);
//		c /= g;
//		d /= g;
//
//		ll a = dp[r][w][0];
//		ll b = dp[r][w][1];
//
//		ll l = lcm(b, d);
//		ll nc = a*(l / b) + c*(l / d);
//		ll nd = l;
//
//		dp[r][w][1] = nd;
//		dp[r][w][0] = nc;
//	}
//
//	g = gcd(dp[r][w][1], dp[r][w][0]);
//	dp[r][w][1] /= g;
//	dp[r][w][0] /= g;
//
//	return;
//}
//
//int main(){
//	int dc = 0;
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		dc++;
//		int red, white;
//		scanf("%d %d", &red, &white);
//		if (!chk[red][white])P(red, white);
//		printf("%llu/%llu\n", dp[red][white][0], dp[red][white][1]);
//		printf("%d %d\n", red, white);
//	}
//}
/*
31 28
*/

#include <stdio.h>
#include <limits.h>

#define ll long long

double dp[77][77];

double P(int r, int w){ // probability (r, c)
	if (dp[r][w] >= 0.0)return dp[r][w];

	dp[r][w] = (double)r / (r+w);
	if (w >= 2){
		dp[r][w] += (double)w / (r + w) * (double)(w - 1) / (r + w - 1) * P(r, w-2);
	}

	return dp[r][w];
}

ll gcd(ll a, ll b){
	ll mod = 1;
	while (mod) {
		mod = a % b;
		a = b;
		b = mod;
	}return a;
}

int main(){
	for (int i = 0; i <= 60; i++)for (int j = 0; j <= 60; j++)dp[i][j] = -1.0;

	int dc = 0;
	int t;
	scanf("%d", &t);

	while (t--){
		dc++;
		int red, white;
		scanf("%d %d", &red, &white);

		double s = P(red, white);

		ll l = 1, r = LLONG_MAX, m;
		ll mother = 100000000000000000;
		int acr = 200;
		while (acr--){
			m = (l + r) / 2;
			double cmp = (double)m / mother;
			if (cmp < s)l = m;
			else
				r = m;
		}

		ll g = gcd(m, mother);

		printf("%lld/%lld\n", m/g, mother/g);
	}
}