#include <stdio.h>

int q[2002][2002];
int r[2002];

int main()
{
	int n, c, m;
	scanf("%d %d %d", &n, &c, &m);

	for (int i = 1; i <= m; i++){
		int a, b, x;
		scanf("%d %d %d", &a, &b, &x);
		q[a][b] += x;
	}

	int nc = 0, ans = 0;

	for (int i = 1; i <= n; i++){
		ans += r[i];
		nc -= r[i];

		for (int j = i + 1; j <= n; j++){
			if (q[i][j]){ // accumulate
				r[j] += q[i][j];
				nc += q[i][j];
			}
		}
		for (int j = n; nc > c && j >= i + 1; j--){
			if (r[j]){ // drop
				if (r[j] > nc - c){
					r[j] -= nc - c;
					nc = c;
				}
				else{
					nc -= r[j];
					r[j] = 0;
				}
			}
		}
	}
	printf("%d\n", ans);
}