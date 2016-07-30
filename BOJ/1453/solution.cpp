#include <stdio.h>

bool c[103];

int main(){

	int n;
	scanf("%d", &n);

	int ans = 0;

	for (int i = 1; i <= n; i++){
		int w;
		scanf("%d", &w);

		if (c[w])ans++;
		else
			c[w] = true;
	}

	printf("%d\n", ans);

}