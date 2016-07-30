#include <stdio.h>
#include <math.h>

int main()
{
	freopen("large_dat6.in", "r", stdin);
	freopen("large_dat6.out", "w", stdout);

	long long m, n;
	while (scanf("%lld %lld", &m, &n) == 2){

		double ans = 0;

		for (long long i = 1; i <= m; i++){ // O(N*lgN)
			ans += i * pow((double)i / m, (double)n); // calc the ways that i is maximum
			ans -= i * pow((double)(i - 1) / m, (double)n); /// calc the ways that i-1 is maximum
		}

		printf("%.6lf\n", ans);
	}
} /* pow 의 시간은  square and multiply 형식 log n */


//#include <stdio.h>
//double End(long long k, long long n, long long m){
//	// calc the ways that used k at least once
//	double x = 1.0, y = 1.0;
//	for (int i = 1; i <= n; i++){
//		x *= k;
//		x /= (double)m;
//		y *= (k - 1);
//		y /= (double)m;
//	}
//
//	return k*(x - y);
//}
//
//int main()
//{
//	long long m, n;
//	while (scanf("%lld %lld", &m, &n) == 2){
//
//		double ans = 0;
//
//		for (long long i = 1; i <= m; i++){
//			ans += End(i, n, m);
//		}
//
//		printf("%.6lf\n", ans);
//	}
//} // O(N*N)