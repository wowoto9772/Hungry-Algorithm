#include <stdio.h>

int main(){

	int h, m;
	scanf("%d %d", &h, &m);

	int t = h * 60 + m;

	int p;
	scanf("%d", &p);

	t += p;

	printf("%d %d\n", ((t / 60) % 24), t % 60);

}