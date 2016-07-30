#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		if (n <= 2)printf("T_T\n");
		else
			printf("%d\n", n / 2 + 1);
	}
}