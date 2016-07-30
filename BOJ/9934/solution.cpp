#include <stdio.h>

int t[1 << 10 + 3];

int main(){
	int n;
	scanf("%d", &n);

	int g = 1 << (n - 1);

	for (int i = 1; i < (1<<n); i++){
		int a;
		scanf("%d", &a);
		while (t[g]){
			if (g * 2 >= (1 << n))g /= 2;
			else if (t[g * 2]){
				if (t[g * 2 + 1]){
					g /= 2;
				}
				else{
					g = g * 2 + 1;
				}
			}
			else{
				g *= 2;
			}
		}
		while (g * 2 < (1 << n)){
			if (t[g * 2])break;
			else
				g *= 2;
		}
		t[g] = a;
	}

	int m = 0;
	int c = 0;
	for (int i = 1; i < (1 << n); i++){
		printf("%d ", t[i]);
		c++;
		if (c == (1 << m)){
			m++;
			printf("\n");
			c = 0;
		}
	}
}