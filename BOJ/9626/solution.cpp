#include <stdio.h>

char str[13][13];
char ans[23][23];

int main(){
	int R, C;
	scanf("%d %d", &R, &C);

	int u, l, r, d;
	scanf("%d %d %d %d", &u, &l, &r, &d);

	for (int i = 0; i < R; i++)scanf("%s", str[i]);

	for (int i = 0; i < u + d + R; i++){
		for (int j = 0; j < l + r + C; j++){
			ans[i][j] = ((i % 2) ^ (j % 2)) ? '.' : '#';
		}
	}

	for (int i = u; i < u + R; i++){
		for (int j = l; j < l + C; j++){
			ans[i][j] = str[i - u][j - l];
		}
	}

	for (int i = 0; i < u + d + R; i++)printf("%s\n", ans[i]);
}