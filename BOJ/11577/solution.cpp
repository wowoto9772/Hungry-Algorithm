#include <stdio.h>

int l[100003];

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++)scanf("%d", &l[i]);

	int c = 0;

	for(int i=1; i<=n-m+1; i++){
		if(l[i]){
			c++;
			for(int j=i; j <= i+m-1; j++)l[j] ^= 1;
		}
	}

	for(int i=n-m+2; i<=n; i++){
		if(l[i]){
			printf("Insomnia");
			return 0;
		}
	}

	printf("%d\n", c);

}
