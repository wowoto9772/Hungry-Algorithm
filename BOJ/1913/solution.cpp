#include <stdio.h>
#include <memory.h>

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

int v[1003][1003];

int main(){

	int n;
	scanf("%d", &n);

	memset(v, 0xff, sizeof(v));

	int d = 0;

	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)v[i][j] = 0;

	int r = 1, c = 1;
	int val = n * n;

	while (val){
		if (!v[r][c]){
			v[r][c] = val--;
			r += dr[d];
			c += dc[d];
			if (v[r][c]){
				r -= dr[d];
				c -= dc[d];
				d++;
				d %= 4;
				r += dr[d];
				c += dc[d];
			}
		}
	}

	int a;
	scanf("%d", &a);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			printf("%d ", v[i][j]);
			if (v[i][j] == a)r = i, c = j;
		}printf("\n");
	}

	printf("%d %d\n", r, c);

}