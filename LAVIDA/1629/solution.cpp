//#include <stdio.h>
//#include <math.h>
//
//int main(){
//	long long x, y, r;
//	while (scanf("%lld %lld %lld", &x, &y, &r) == 3){
//		if (!x && !y && !r)return 0;
//
//		long long ans = 0;
//
//		x = y = 0;
//
//		long long y_ = 0;
//
//		for (int x_ = r; y_ < r; y_++){
//			long long k = x_*x_ + y_*y_;
//			while (k >= r*r){
//				x_--;
//				k = x_*x_ + y_*y_;
//			}
//			ans += x_ + 1;
//		}
//
//		ans *= 4;
//
//		printf("%lld\n", ans);
//	}
//}

#include <stdio.h>
#include <math.h>

int main(){
	long long x, y, r;
	while (scanf("%lld %lld %lld", &x, &y, &r) == 3){
		if (!x && !y && !r)return 0;

		long long ans = 0;

		for (long long a = 0; a < r; a++){ // value a is same value y_
			long long k = r*r - a*a;
			
			double k_ = sqrt((double)k);

			int k__ = k_;
			if (k_ - k__ > 1e-11){
				ans += k__ + 1;
			}
			else
				ans += k__;
		}

		ans *= 4;

		printf("%lld\n", ans);
	}
}