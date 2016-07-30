#include <stdio.h>

int S[1000];

int main(){
	int a, b;
	scanf("%d %d", &a, &b);

	int top = 0;
	for (int i = 1; i <= 1000 && top <= 1000; i++){
		for (int j = 1; j <= i && top <= 1000; j++){
			top++;
			S[top] = S[top - 1] + i;
		}
	}
	
	printf("%d\n", S[b] - S[a - 1]);
}