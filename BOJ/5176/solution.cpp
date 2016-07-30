#include <stdio.h>

bool ch[503];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int p, m;
		scanf("%d %d", &p, &m);

		for (int i = 1; i <= m; i++)ch[i] = false;

		for (int i = 1; i <= p; i++) {
			int a;
			scanf("%d", &a);
			ch[a] = true;
		}

		int ans = 0;
		for (int i = 1; i <= m; i++)if (ch[i])ans++;

		printf("%d\n", p - ans);

	}

}