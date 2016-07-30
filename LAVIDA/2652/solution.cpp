#include <stdio.h>

int I[1003];

int main(){
	int n, a, b;
	while (scanf("%d %d %d", &n, &a, &b) == 3 && n && a && b){
		for (int i = 1; i <= n; i++)scanf("%d", &I[i]);
		int max = -1, x = -1;
		for (int i = a; i <= b; i++){
			int gap = I[i + 1] - I[i];
			if (gap < 0)gap *= -1;
			if (max <= gap){
				max = gap;
				x = i;
			}
		}
		printf("%d\n", x);
	}
}