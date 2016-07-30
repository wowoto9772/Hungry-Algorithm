#include <stdio.h>
#include <queue>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int w, h, k;
		scanf("%d %d %d", &w, &h, &k);

		bool chk[55][55] = { 0 };
		int arr[55][55] = { 0 };
		
		for (int i = 1; i <= k; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			arr[x][y] = 1;
		}

		queue <int> qx, qy;

		int ans = 0;
		
		for (int i = 0; i < w; i++){
			for (int j = 0; j < h; j++){
				if (chk[i][j])continue;
				if (arr[i][j]){
					qx.push(i), qy.push(j);
					ans++;

					while (!qx.empty()){
						int fx = qx.front(), fy = qy.front();
						qx.pop(), qy.pop();

						for (int k = 0; k < 4; k++){
							int nx = fx + dx[k], ny = fy + dy[k];
							if (nx < 0 || ny < 0 || nx >= w || ny >= h)continue;
							if (chk[nx][ny])continue;
							if (!arr[nx][ny])continue;
							chk[nx][ny] = true;
							qx.push(nx), qy.push(ny);
						}
					}
				}
			}
		}

		printf("%d\n", ans);
	}
}