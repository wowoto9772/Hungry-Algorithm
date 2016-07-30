#include <stdio.h>

int main(){
	long long n;
	while (scanf("%lld", &n) == 1 && n){

		n--;

		if (n == 0)printf("{ }\n");
		else{

			printf("{ ");

			int a[2003] = { 0, 1 }, x = 1, t = 0;

			for (long long i = 0; (1LL << i) <= n && i <= 63; i++){
				long long k = 1LL << i;
				if (n&k){
					t++;
					if (t > 1)printf(", ");
					for (int j = 1; j <= x; j++)printf("%d", a[j]);
				}
				int b[2003] = { 0, };
				for (int j = x; j >= 1; j--){
					b[j] += a[j] * 3;
					if (b[j] >= 10){
						b[j - 1] += b[j] / 10;
						b[j] %= 10;
					}
				}
				if (b[0]){
					x++;
					for (int j = 1; j <= x; j++)a[j] = b[j - 1];
				}
				else{
					for (int j = 1; j <= x; j++)a[j] = b[j];
				}
			}
			printf(" }\n");

		}
	}
}