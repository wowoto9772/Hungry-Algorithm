#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX 1000000LL

int main(){
	int tc = 0;
	double m;
	while (scanf("%lf", &m) == 1){
		if (m == 0.0)break;

		double ans = MAX * MAX;
		int x, y;

		for (int i = 1; i <= MAX; i++){
			// m = x / i
			// x = m * i

			ll x1 = m * i;

			if (x1 >= 1 && x1 <= MAX){
				double cmp = (double)x1 / i;
				if (ans > fabs(m - cmp)){
					ans = fabs(m - cmp);
					x = x1, y = i;
				}
			}

			x1++;
			
			if (x1 >= 1 && x1 <= MAX){
				double cmp = (double)x1 / i;
				if (ans > fabs(m - cmp)){
					ans = fabs(m - cmp);
					x = x1, y = i;
				}
			}
		}

		printf("Case %d is best approximated as %d/%d\n", ++tc, x, y);
		printf("\n");
	}
}