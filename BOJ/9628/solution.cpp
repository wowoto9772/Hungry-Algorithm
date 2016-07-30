#include <stdio.h>
#include <algorithm>

using namespace std;

int e[1003], d[1003];
// eaten, distribution

int main(){
	int n;
	scanf("%d", &n);

	int tot = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d %d", &e[i], &d[i]);
		tot += d[i];
	}

	// 1st ... nth
	
	double ir = 10000000, il = 0.0;

	for (int i = 2; i <= n; i++){

		// e[i-1] + d[i-1](x) >= e[i] + d[i](x)

		// (d[i-1] - d[i])(x) >= e[i] - e[i-1]

		// [type] (x) >= (e[i] - e[i-1]) / (d[i-1] - d[i])

		int j = i - 1;

		if (d[j] == d[i]){

			if (e[j] < e[i]){
				printf("-1\n");
				return 0;
			}

		}
		else{

			double cmp = (e[i] - e[j]) / (double)(d[j] - d[i]);

			if (d[j] > d[i]){
				// positive
				il = max(il, cmp);
			}
			else{
				// negative
				ir = min(ir, cmp);
			}

		}
		 
	}

	double ans = tot * il;

	if (il >= ir + 1e-9 || ans > 10000000 + 1e-9)printf("-1\n");
	else
		printf("%.12lf\n", ans);

}