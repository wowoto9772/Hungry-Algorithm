#include <stdio.h>

int pre[1003], in[1003];

void split(int pl, int pr, int il, int ir) {

	if (pr - pl == 0)return;

	int root = pre[pl];

	for (int i = il; i < ir; i++) {
		if (in[i] == root) {
			split(pl + 1, pl + 1 + (i - il), il, i);
			split(pl + 1 + (i - il), pr, i + 1, ir);
			break;
		}
	}

	printf("%d ", root);

}

int main()
{

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)scanf("%d", &pre[i]);
		for (int i = 0; i < n; i++)scanf("%d", &in[i]);

		split(0, n, 0, n);

		printf("\n");

	}

}