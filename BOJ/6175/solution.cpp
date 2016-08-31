#include <stdio.h>

char str[103][103];

int gn, gm;

int dp[103][103][18];

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int n, m;

int dy(int x, int y, int t){

	if(t == 0){
		if(x == gn && y == gm)return 1;
		return 0;
	}
	
	int &ret = dp[x][y][t];

	if(ret != -1)return ret;

	ret = 0;

	for(int i=0; i<4; i++){
		int nx = x + dr[i], ny = y + dc[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
		if(str[nx][ny] == '*')continue;
		ret += dy(nx, ny, t-1);
	}

	return ret;

}

int main(){

	int t;
	scanf("%d %d %d", &n, &m, &t);

	for(int i=0; i<n; i++){
		scanf("%s", str[i]);
		for(int j=0; j<m; j++){
			for(int k=0; k<=t; k++){
				dp[i][j][k] = -1;
			}
		}
	}

	int sn, sm;
	scanf("%d %d %d %d", &sn, &sm, &gn, &gm);

	sn--, sm--, gn--, gm--;

	printf("%d\n", dy(sn, sm, t));

}
