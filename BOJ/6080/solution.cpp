#include <stdio.h>

#include <queue>

using namespace std;

int e[1003][1003];

int dr[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool chk[1003][1003];

int main(){

	int r, c;
	scanf("%d %d", &r, &c);

	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			scanf("%d", &e[i][j]);
		}
	}

	queue < pair<int,int> > q;

	int x = 0;

	for(int i=1; i<=r; i++){

		for(int j=1; j<=c; j++){

			if(chk[i][j])continue;

			if(!e[i][j])continue;

			x++;

			q.emplace(i, j);

			while(!q.empty()){

				pair<int,int> f = q.front();q.pop();

				for(int k=0; k<8; k++){

					pair<int,int> g = {f.first + dr[k], f.second + dc[k]};

					if(!e[g.first][g.second])continue;

					if(chk[g.first][g.second])continue;

					chk[g.first][g.second] = true;

					q.emplace(g);

				}

			}

		}

	}

	printf("%d\n", x);

}
