#include <stdio.h>

int chk[1027];
int ans[1027];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int p, q;
		scanf("%d %d", &p, &q);

		for (int j = 0; j < q; j++)chk[j] = -1;

		printf("%d", p / q);
		p %= q;

		printf(".");

		int top = 0;

		while (chk[p] == -1) {
			chk[p] = top;
			p = p * 10;
			ans[top++] = p / q;
			p %= q;
		}

		for (int i = 0; i < chk[p]; i++)printf("%d", ans[i]);

		printf("(");
		for (int i = chk[p]; i < top; i++)printf("%d", ans[i]);
		printf(")");

		puts("");

	}

}