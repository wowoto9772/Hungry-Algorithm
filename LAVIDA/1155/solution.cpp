#include <stdio.h>
#include <math.h>
#include <algorithm>
#define MAX 2000000000

using namespace std;

long long A[400000];
int top;

int main()
{
	for (long long i = 0; i < 31; i++){
		long long x = pow(2, i);
		if (x > MAX)break;
		for (long long j = 0; j < 31; j++){
			long long y = pow(3, j);
			if (y > MAX || x * y > MAX)break;
			for (long long k = 0; k < 31; k++){
				long long z = pow(5, k);
				if (z > MAX || x * y * z > MAX)break;
				for (long long l = 0; l < 31; l++){
					long long w = pow(7, l);
					if (w > MAX || x * y * z * w > MAX)break;
					A[top++] = x * y * z * w;
				}
			}
		}
	}

	sort(A, A + top);

	int n;
	while (scanf("%d", &n) == 1 && n){
		printf("The %d", n);
		int k = n % 10, l = n % 100;
		if (l / 10 == 1)printf("th");
		else if (k == 1)printf("st");
		else if (k == 2)printf("nd");
		else if (k == 3)printf("rd");
		else{
			printf("th");
		}
		printf(" humble number is %lld.\n", A[n - 1]);
	}
}