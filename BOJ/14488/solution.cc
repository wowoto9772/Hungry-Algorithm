#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

ll x[50003], y[50003];

int main(){

	int n;
	double t;
	scanf("%d %lf", &n, &t);

	double l = -2e+18, r = 2e+18;

	for (int i = 1; i <= n; i++)scanf("%lld", &x[i]);
	for (int i = 1; i <= n; i++)scanf("%lld", &y[i]);

	for (int i = 1; i <= n; i++){
		l = max(x[i] - y[i] * t, l);
		r = min(x[i] + y[i] * t, r);
	}

	printf("%d\n", l <= r);

}