#include <stdio.h>

int main(){

	int p[202];
	for (int i = 1; i <= 200; i++)p[i] = i;

	int t = 1;
	int s[1002] = { 0 };
	for (int i = 1; i <= 1000; i++){
		if (!p[t])t++;
		p[t]--;
		s[i] = s[i - 1] + t;
	}

	int a, b;
	scanf("%d %d", &a, &b);

	if (a > b){
		int t = a;
		a = b;
		b = t;
	}

	printf("%d\n", s[b] - s[a - 1]);
}