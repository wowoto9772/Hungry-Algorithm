#include <stdio.h>
#define ll long long
#define mod 56

ll p[32] = { 0, 1, 1 };

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 3; i <= n; i++){
		p[i] = p[i - 1] + p[i - 2];
	}

	for (int i = 1; i <= n; i++){
		p[i] %= mod;
		if (!p[i])p[i] = 1;
		for (int j = 1; j <= p[i]; j++)printf("*");
		printf("\n");
	}

}