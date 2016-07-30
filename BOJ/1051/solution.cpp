#include <stdio.h>

int x[52][52];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)scanf(" %1d", &x[i][j]);

	int ans = 1;
	for (int i = 1; i <= n - ans; i++){
		for (int j = 1; j <= m - ans; j++){
			for (int k = ans; i+k <= n && j+k <= m; k++){
				if (x[i][j] == x[i + k][j] && x[i][j] == x[i][j + k] && x[i + k][j] == x[i + k][j + k]){
					ans = k+1;
				}
			}
		}
	}

	printf("%d\n", ans*ans);
}