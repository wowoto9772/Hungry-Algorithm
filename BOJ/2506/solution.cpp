#include <stdio.h>

int main(){

	int n;
	scanf("%d", &n);

	int ac = 0;
	int score = 0;

	for (int i = 1; i <= n; i++){

		int a;
		scanf("%d", &a);

		ac += a;
		if (a == 0)ac = 0;

		score += ac;

	}

	printf("%d\n", score);
}