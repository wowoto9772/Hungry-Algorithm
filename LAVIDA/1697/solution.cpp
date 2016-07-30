#include <stdio.h>
#include <memory.h>

int min(int a, int b){ return a < b ? a : b; }

int d[10][10];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		memset(d, 0x2f, sizeof(d));

		for (int i = 1; i <= m; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if (d[a][b] > c)d[a][b] = c;
		}

		for (int k = 1; k <= n; k++){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		for (int i = 1; i < n; i++)printf("%d ", d[i][i]);
		printf("%d\n", d[n][n]);
	}
}