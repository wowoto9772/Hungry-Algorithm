#include <stdio.h>

int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int g = 1;
		int c = 1;
		while (g%n){
			g %= n;
			g = g * 10 + 1;
			c++;
		}
		printf("%d\n", c);
	}
}