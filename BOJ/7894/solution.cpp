#include <stdio.h>
#include <memory.h>
#include <math.h>

bool p[10000003];
int P[1000003];
int top;
int A[1000003];

int main()
{
	for (int i = 2; i < 10000000; i++){
		if (!p[i]){
			P[top++] = i;
			for (int j = i + i; j < 10000000; j += i){
				p[j] = true;
			}
		}
	}

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);

		memset(A, 0, sizeof(A));

		for (int j = 0; j < top && P[j] <= a; j++){
			for (long long k = P[j]; k <= a; k *= P[j]){
				A[j] += a / k;
			}
		}

		double ans = 0;

		for (int j = 0; j < top && P[j] <= a; j++){
			double k = log10((double)P[j]);
			k *= A[j];
			ans += k;
		}

		long long ans_ = ans;
		ans_++;

		printf("%lld\n", ans_);
	}
}