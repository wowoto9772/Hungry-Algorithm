#include <stdio.h>
#include <memory.h>

int dx[17] = { -2, -2, -1, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 1, 2, 2};
int dy[17] = { 1, -1, 2, 1, 0, -1, -2, 1, -1, 2, 1, 0, -1, -2, 1, -1};
long long d[103][103][53];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);
		int sx, sy, gx, gy, c;
		scanf("%d %d %d %d %d", &sx, &sy, &gx, &gy, &c);

		memset(d, 0, sizeof(d));

		d[sx][sy][0] = 1;
		for (int x = 1; x <= c; x++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					for (int k = 0; k < 16; k++){
						int ni = i + dx[k];
						int nj = j + dy[k];
						if (ni < 0)continue;
						if (nj < 0)continue;
						if (ni >= n)continue;
						if (nj >= n)continue;
						d[ni][nj][x] += d[i][j][x - 1];
					}
				}
			}
		}

		printf("%lld\n", d[gx][gy][c]);
	}
}