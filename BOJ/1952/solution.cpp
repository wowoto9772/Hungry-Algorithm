#include <stdio.h>

bool chk[103][103];

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int main(){

	int m, n;
	scanf("%d %d", &m, &n);

	for(int i=0; i<=m+1; i++){
		for(int j=0; j<=n+1; j++){
			if(i == 0 || i == m+1 || j == 0 || j == n+1)chk[i][j] = true;
		}
	}

	int x = 1;
	int y = 0;

	int r = 1, c = 1;
	chk[r][c] = true;
	int d = 0;

	while(x < m*n){
		int nr = r + dr[d], nc = c + dc[d];
		if(chk[nr][nc]){
			y++;
			d++;
			d %= 4;
			continue;
		}else{
			chk[nr][nc] = true;
			r = nr, c = nc;
			x++;
		}
	}

	printf("%d\n", y);

}
