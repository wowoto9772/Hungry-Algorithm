#include <stdio.h>

bool c[103][103];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int a, b;
		scanf("%d %d", &a, &b);

		for (int i = a; i < a + 10; i++)for (int j = b; j < b + 10; j++)c[i][j] = true;

	}

	int ans = 0;
	for (int i = 0; i <= 101; i++) {
		for (int j = 0; j <= 101; j++) {
			if (j < 101 && !c[i][j] && c[i][j + 1])ans++;
			if (j && c[i][j - 1] && !c[i][j])ans++;
			if (i < 101 && !c[i][j] && c[i + 1][j])ans++;
			if (i && c[i - 1][j] && !c[i][j])ans++;
		}
	}

	printf("%d\n", ans);

}