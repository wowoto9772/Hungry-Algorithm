#include <stdio.h>
#include <limits.h>
#include <algorithm>
#define n 20

using namespace std;

int d[22][22];

int main(){
	int f;
	int TS = 0;
	while (scanf("%d", &f) == 1){
		for (int i = 1; i <= 20; i++){
			for (int j = 1; j <= 20; j++){
				d[i][j] = INT_MAX;
			}
		}
		for (int i = 1; i <= f; i++){
			int a;
			scanf("%d", &a);
			d[1][a] = d[a][1] = 1;
		}
		for (int i = 2; i < n; i++){
			scanf("%d", &f);
			for (int j = 1; j <= f; j++){
				int a;
				scanf("%d", &a);
				d[i][a] = d[a][i] = 1;
			}
		}

		for (int k = 1; k <= n; k++){
			for (int i = 1; i <= n; i++){
				if (d[i][k] == INT_MAX)continue;
				for (int j = 1; j <= n; j++){
					if (d[k][j] == INT_MAX)continue;
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		
		printf("Test Set #%d\n", ++TS);

		int q;
		scanf("%d", &q);

		while (q--){
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%d to %d: %d\n", a, b, d[a][b]);
		}

		printf("\n"); // blank line
	}
}