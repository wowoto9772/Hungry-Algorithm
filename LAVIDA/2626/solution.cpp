#include <stdio.h>
#include <queue>

#define MAX 1000000007

using namespace std;

int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
int dir[103][103];

int ans;
int dp[13][4][13];
int jx[13] = { 1, }, jy[13] = { 1, };
bool vst[13];
int k;

int next_dir(int w, int t){
	return (w + t) % 4;
}

void Search(int p, int t, int r){

	if (ans <= t)return;

	int cdir = next_dir(dir[jx[p]][jy[p]], t);
	if (!r){
		int nans = t + dp[p][cdir][k + 1];
		if (ans > nans)ans = nans;
		return;
	}

	for (int i = 1; i <= k; i++){
		if (ans <= t)return;
		if (vst[i])continue;
		vst[i] = true;
		Search(i, t + dp[p][cdir][i], r - 1);
		vst[i] = false;
	}
}

int main(){

	int r, c;
	while (scanf("%d %d", &r, &c) == 2 && r && c){
		char str[105] = { 0 };
		for (int i = 1; i <= r; i++){
			scanf("%s", str + 1);
			for (int j = 1; j <= c; j++){
				if (str[j] == 'E')dir[i][j] = 0;
				else if (str[j] == 'S')dir[i][j] = 1;
				else if (str[j] == 'W')dir[i][j] = 2;
				else
					dir[i][j] = 3;
			}
		}

		scanf("%d", &k);
		for (int i = 1; i <= k; i++){
			scanf("%d %d", &jx[i], &jy[i]);
		}
		jx[k + 1] = r, jy[k + 1] = c;

		int pass[104][104];

		for (int p = 0; p <= k; p++){ // position
			for (int w = 0; w <= 3; w++){ // wait time
				queue <int> x, y, t;
				x.push(jx[p]);
				y.push(jy[p]);
				t.push(0);

				for (int a = 1; a <= r; a++)for (int b = 1; b <= c; b++)pass[a][b] = MAX;
				pass[jx[p]][jy[p]] = 0;

				while (!x.empty()){
					int cx = x.front(), cy = y.front(), ct = t.front();
					x.pop(), y.pop(), t.pop();

					for (int w2 = 0; w2 <= 3; w2++){
						int cdir = next_dir(dir[cx][cy], w + (ct + w2));

						int nx = cx + dr[cdir];
						if (nx < 1 || nx > r)continue;
						int ny = cy + dc[cdir];
						if (ny < 1 || ny > c)continue;

						if (pass[nx][ny] > ct + w2 + 1){
							pass[nx][ny] = ct + w2 + 1;
							x.push(nx);
							y.push(ny);
							t.push(pass[nx][ny]);
						}
					}
				}

				for (int np = 1; np <= k + 1; np++){
					int cw = next_dir(dir[jx[p]][jy[p]], w);
					dp[p][cw][np] = pass[jx[np]][jy[np]];
				}
			}
		}

		ans = MAX;

		Search(0, 0, k);

		printf("%d\n", ans);
	}
}