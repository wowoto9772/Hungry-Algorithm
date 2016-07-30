#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int D[200003];
long long S[200003];

int main()
{
	FILE *f = fopen("large_dat14.in", "w");
	srand(time(NULL));
	int n_ = rand() % 1000 + 199000;
	long long A_ = n_ * 1000;
	fprintf(f, "%d %d\n", n_, A_);
	int b_ = rand () % 1000000 + 1;
	for (int i = 1; i < n_; i++){
		fprintf(f, "%d ", b_);
		b_ = rand() % 1000000 + 1;
	}fprintf(f, "%d\n", b_);
	fclose(f);

	freopen("large_dat14.in", "r", stdin);
	freopen("large_dat14.out", "w", stdout);

	long long n, A;
	while (scanf("%lld %lld", &n, &A) == 2){
		long long ret = 0;
		for (int i = 1; i <= n; i++){
			scanf("%lld", &D[i]);
			S[i] += S[i - 1] + D[i];
		}

		for (int i = 1; i <= n; i++){
			long long a = A - (ret + S[n] - S[i]); // is minimum value
			long long b = A - (n - 1); // is maximum value
			if (b > D[i]){
				b = D[i];
			}
			if (a <= 0)a = 1;
			int c = D[i] - b;
			c += a - 1;
			printf("%d", c);
			if (i < n)printf(" ");
			ret += b;
		}printf("\n");
	}
}

/*
3 18
9 9 9
*/

//#include <stdio.h>
//
//long long D[200003];
//
//int main()
//{
//	long long n, A;
//	scanf("%lld %lld", &n, &A);
//	long long ret = 0, ret2 = 0;
//	for (int i = 1; i <= n; i++){
//		scanf("%lld", &D[i]);
//		ret2 += D[i];
//	}
//
//	ret = n;
//
//	for (int i = 1; i <= n; i++){
//		ret--;
//		ret2 -= D[i];
//		long long a = A - ret2; // is minimum value
//		long long b = A - ret; // is maximum value
//		if (b > D[i]){
//			b = D[i];
//		}
//
//		if (a <= 0)a = 1;
//		int c = D[i] - b;
//		c += a - 1;
//		printf("%d", c);
//		if (i < n)printf(" ");
//		ret2 += b;
//		ret += a;
//	}printf("\n");
//}