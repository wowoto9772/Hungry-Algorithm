#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int a, b, n;
		scanf("%d %d %d", &a, &b, &n);

		int top = 0;
		int A[12] = { 0 }, B[12] = { 0 };

		long long k = 0;

		for (int i = 1; i <= n; i++){
			int x;
			scanf("%d", &x);
			if (i <= a)A[i] = x;
			else{
				sort(A + 1, A + 1 + a);
				if (A[1] < x)A[1] = x;
			}
			if (i <= b)B[i] = x;
			else{
				sort(B + 1, B + 1 + b);
				if (B[b] > x)B[b] = x;
			}
			k += x;
		}

		for (int i = 1; i <= a; i++)k -= A[i];
		for (int i = 1; i <= b; i++)k -= B[i];

		n -= a + b;
		
		double s = k / (double)n;
		printf("%.6lf\n", s);
	}
}