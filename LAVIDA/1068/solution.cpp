#include <stdio.h>

int I[103][103];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)scanf("%d", &I[i][j]);

		int a, b;
		scanf("%d %d", &a, &b);

		for (int i = 1; i <= a; i++){
			for (int j = 1; j <= b; j++){
				int x;
				scanf("%d", &x);
				I[i][j] += x;
			}
		}

		if (n == a && m == b){
			for (int i = 1; i <= a; i++){
				for (int j = 1; j < b; j++)printf("%d ", I[i][j]);
				printf("%d\n", I[i][b]);
			}
		}
		else{
			printf("Impossible\n");
		}
	}
}