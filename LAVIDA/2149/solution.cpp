#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		int k;
		int x = 1;
		if (!(n % 2)){
			k = n / 2;
			n--;
		}
		else{
			k = (n + 1) / 2;
		}
		for (int i = 1; i; i+=x){
			for (int j = 1; j <= k - i; j++)printf(" ");
			if(i == 1)printf("$");
			else{
				printf("$");
				for (int j = 1; j <= (i-1)*2-1; j++)printf(" ");
				printf("$");
			}
			printf("\n");
			if (i == k)x *= -1;
		}

	}
}