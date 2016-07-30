//#include <stdio.h>
//#include <limits.h>
//#define ll long long
//
//int n;
//
//ll I[100003];
//ll A(ll a){ return a < -a ? -a : a; }
//ll F(ll a){
//	ll ret = 0;
//	for (ll i = 2; i <= n; i++){
//		ret += A(I[1] + a*(i - 1) - I[i]);
//	}return ret;
//}
//
//int main()
//{
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++){
//		scanf("%lld", &I[i]);
//	}
//
//	ll min = 0, max = I[n];
//
//	while (min != max){
//		ll l = (2 * min + max) / 3;
//		ll r = (min + max * 2) / 3;
//
//		if (F(min) > F(max)){ // find for interval(function)'s minimum
//			if (min == l)min++;
//			else
//				min = l;
//		} // F(min) < F(max) : find for interval(function)'s maximum
//		else{
//			if (max == r)max--;
//			else
//				max = r;
//		}
//	}
//
//	printf("%lld\n", F(min));
//}

#include <stdio.h>
#include <limits.h>

#define ll long long

int n;

ll I[100003];
double mm(double a, double b){ return a < b ? a : b; }
double A(double a){ return a < -a ? -a : a; }
double F(double a){
	double ret = 0;
	for (ll i = 2; i <= n; i++){
		ret += A(I[1] + a*(i - 1) - I[i]);
	}return ret;
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%lld", &I[i]);
	}

	double min = 0, max = I[n]; // interval
	int x = 100; // 200 : accuracy

	while (min != max && x--){
		double l = (2 * min + max) / 3;
		double r = (min + max * 2) / 3;

		if (F(l) > F(r)){ // find for interval(function)'s minimum
			min = l;
		} // F(l) < F(r) : find for interval(function)'s maximum
		else{
			max = r;
		}
	}

	// F((min+max)/2) is minimum value

	double k = (min + max) / 2;
	ll a = (ll)k;
	ll b = a + 1;

	printf("%.0lf\n", mm(F(a), F(b)));
}

/*
	drawing graph & max or min (one point)
	tunary search : find for interval's maximum or minimum value
	sort ==> two adjacent points's slope (- ==> + : minimum value)
									     (+ ==> - : maximum value)
*/