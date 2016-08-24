#include <stdio.h>

int main(){

	int n, k, p, w;

	scanf("%d %d %d %d", &n, &k, &p, &w);

	printf("%d\n", p / w + ((p%w) ? 1 : 0));

}
