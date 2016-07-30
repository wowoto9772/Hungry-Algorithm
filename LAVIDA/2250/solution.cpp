#include <stdio.h>

int main(){
	int n, tc = 0;
	while (scanf("%d", &n) == 1 && n){
		int g = 5;
		int ans = 0;
		while (g <= n){
			ans += n / g;
			g *= 5;
		}
		printf("Case #%d: %d\n", ++tc, ans);
	}
}