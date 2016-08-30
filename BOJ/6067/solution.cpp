#include <stdio.h>

#include <queue>
#include <vector>

#include <algorithm>

using namespace std;

bool chk[703][703];
int h[703][703];

int dr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dc[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main(){

	int r, c;
	scanf("%d %d", &r, &c);

	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			scanf("%d", &h[i][j]);
		}
	}

	int ans = 0;

	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			if(chk[i][j])continue;
			if(!h[i][j])continue;

			bool hill = true;

			queue < pair<int,int> > q;
			q.emplace(i, j);

			while(!q.empty()){

				pair<int,int> f = q.front();q.pop();

				int rr = f.first, cc = f.second;

				for(int k=0; k<8; k++){
					pair<int,int> g = {rr+dr[k], cc+dc[k]};

					int nr = g.first, nc = g.second;

					// out of range
					if(nr < 1 || nc < 1 || nr > r || nc > c)continue;

					if(!h[nr][nc])continue;

					if(h[nr][nc] > h[rr][cc]){
						hill = false;
					}
					else if(!chk[nr][nc] && h[nr][nc] == h[rr][cc]){
						chk[nr][nc] = true;
						q.emplace(g);
					}
				}
			}

			ans += hill;
		}
	}

	printf("%d\n", ans);

}
