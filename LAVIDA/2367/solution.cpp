#include <stdio.h>

char str[39][39];
int di[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dj[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int m, n;
		scanf("%d %d", &m, &n);

		int x = 0;

		for (int i = 1; i <= m; i++){
			scanf("%s", str[i] + 1);
			for (int j = 1; j <= n; j++)if (str[i][j] == '@')x++;
		}

		printf("%d %d\n", m*n, x);

		if (!x)printf("No Mine\n");
		else{
			for (int i = 1; i <= m; i++){
				for (int j = 1; j <= n; j++){
					if (str[i][j] == '@'){
						printf("@");
					}
					else{
						int c = 0;
						for (int k = 0; k < 9; k++){
							if (str[i + di[k]][j + dj[k]] == '@')c++;
						}
						printf("%d", c);
					}
				}printf("\n");
			}
		}
	}
}