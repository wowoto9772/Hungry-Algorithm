#include <stdio.h>
#define I(a, b) I[a][b]

int I[33][33];

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)scanf("%d", &I[i][j]);
	
	bool flag = false;

	for (int i = 1; !flag && i <= n - 2; i++){
		for (int j = 1; !flag && j <= m - 2; j++){
			int x = 0, y = 0, z = 0;
			for (int k = i+1; k <= i + 2; k++){
				if (I(i, j) == I(k, j)){
					x++;
				}
				if (I(i, j + 1) == I(k, j + 1)){
					y++;
				}
				if (I(i, j + 2) == I(k, j + 2)){
					z++;
				}
			}
			if (x == 2 || y == 2 || z == 2){
				x = y = z = 0;
				for (int k = j + 1; k <= j + 2; k++){
					if (I(i, j) == I(i, k)){
						x++;
					}
					if (I(i + 1, j) == I(i + 1, k)){
						y++;
					}
					if (I(i + 2, j) == I(i + 2, k)){
						z++;
					}
				}
				if (x == 2 || y == 2 || z == 2){
					flag = true;
				}
			}
		}
	}

	if (flag)printf("Yes\n");
	else
		printf("No\n");
}