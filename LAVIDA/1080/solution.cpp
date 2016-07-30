#include <stdio.h>

int a[103][103];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int r, c;
		scanf("%d %d", &r, &c);

		for (int i = 1; i <= r; i++)for (int j = 1; j <= c; j++)scanf("%d", &a[i][j]);

		for (int i = 1; i <= c; i++){
			for (int j = 1; j < r; j++)printf("%d ", a[j][i]);
			printf("%d\n", a[r][i]);
		}
	}
}