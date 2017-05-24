#include <cstdio>

using namespace std;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

bool check[53][53];
int e[53][53];

int main(){
	
	int r, c;
	scanf("%d %d", &r, &c);
	
	int x, y, d;
	scanf("%d %d %d", &x, &y, &d);
	
	for(int i=0; i<r; i++)for(int j=0; j<c; j++)scanf("%d", &e[i][j]);
	
	while(true){
		check[x][y] = true;
		int cnt = 0;
		for(int i=0; i<4; i++){
			int nx = x + dr[i], ny = y + dc[i];
			if(nx < 0 || nx >= r || ny < 0 || ny >= c || e[nx][ny] || check[nx][ny])cnt++;
		}
		
		if(cnt == 4){
			int nx = x - dr[d], ny = y - dc[d];
			if(nx < 0 || nx >= r || ny < 0 || ny >= c || e[nx][ny]){ // wall
				break;
			}else{
				x = nx, y = ny;
			}
		}else{
			int nd = d - 1;
			if(nd < 0)nd += 4;
			int nx = x + dr[nd], ny = y + dc[nd];
			if(nx < 0 || nx >= r || ny < 0 || ny >= c || check[nx][ny] || e[nx][ny]){}
			else{
				x = nx, y = ny;
			}
			d = nd;
		}
	}
	
	int ans = 0;
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			ans += (check[i][j] == true);
		}
	}
	
	printf("%d\n", ans);
	
}