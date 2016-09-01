#include <stdio.h>

#include <vector>

using namespace std;

int n, tot;

char str[33][33];

int dr[] = {1, 1, -1, -1};
int dc[] = {1, -1, 1, -1};

vector < pair <int,int> > v;

bool chk[33][33];

bool ended;

void dfs(int x, int y, int c){

	if(c == tot){
		ended = true;
		for(int i=0; i<v.size(); i++){
			printf("%d %d\n", ++v[i].first, ++v[i].second);
		}
		return ;
	}

	for(int i=0; i<4 && !ended; i++){

		int nx = x + dr[i], ny = y + dc[i];

		if(nx < 0 || nx >= n || ny < 0 || ny >= n)continue;

		if(str[nx][ny] == 'o'){

			int nnx = x + 2 * dr[i], nny = y + 2 * dc[i];

			if(nnx < 0 || nnx >= n || nny < 0 || nny >= n)continue;

			if(str[nnx][nny] == '+'){

				if(chk[nnx][nny])continue;

				chk[nnx][nny] = true;

				str[nx][ny] = '+';
				
				v.emplace_back(nnx, nny);

				dfs(nnx, nny, c+1);

				str[nx][ny] = 'o';

				v.pop_back();

				chk[nnx][nny] = false;

			}

		}

	}

}

int main(){

	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%s", str[i]);
		for(int j=0; j<n; j++){
			if(str[i][j] == 'o')tot++;
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(str[i][j] == 'K'){
				chk[i][j] = true;
				v.emplace_back(i, j);
				str[i][j] = '+';

				dfs(i, j, 0);

				if(ended)return 0;
				str[i][j] = 'K';
				chk[i][j] = false;
				v.pop_back();
			}
		}
	}

	printf("impossible");

}
