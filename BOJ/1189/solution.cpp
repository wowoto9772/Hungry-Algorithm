#include <stdio.h>

int r, c, m;

int ans;

bool chk[7][7];

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

char str[8][8];

void dfs(int x, int y, int d){

	if(d == m){
		if(x == 0 && y == c-1)ans++;
		return ;
	}

	for(int i=0; i<4; i++){

		int nx = x + dr[i], ny = y + dc[i];

		if(nx < 0 || nx >= r || ny < 0 || ny >= c)continue;

		if(chk[nx][ny])continue;

		if(str[nx][ny] == 'T')continue;

		chk[nx][ny] = true;

		dfs(nx, ny, d+1);

		chk[nx][ny] = false;

	}
	
}

int main(){

	scanf("%d %d %d", &r, &c, &m);

	for(int i=0; i<r; i++){
		scanf("%s", str[i]);
	}

	chk[r-1][0] = true;
	dfs(r-1, 0, 1);

	printf("%d\n", ans);

}
