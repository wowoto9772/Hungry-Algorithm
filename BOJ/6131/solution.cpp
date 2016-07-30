#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int ans = 0;

	for (int i = 1; i <= 500; i++){
		for (int j = i; j*j <= i*i+n; j++){
			if (i*i + n == j*j){
				ans++;
			}
		}
	}

	printf("%d\n", ans);
}