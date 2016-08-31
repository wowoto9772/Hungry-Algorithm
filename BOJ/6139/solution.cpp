#include <stdio.h>

int main(){

	int n, k;
	scanf("%d %d", &n, &k);

	for(int i=1; i<=k; i++){

		int s, m, r;
		scanf("%d %d %d", &s, &m, &r);

		int work = n / s + ((n % s) ? 1 : 0);

		int dvs = work / m + ((work % m) ? 1 : 0);

		int ans = (dvs - 1) * r + work;

		printf("%d\n", ans);

	}

}
