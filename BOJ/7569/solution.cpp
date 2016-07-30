#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int chk[103][103][103];

class ele{
public:
	int r, c, h;
	ele(){}
	ele(int h_, int r_, int c_){
		h = h_, r = r_, c = c_;
	}
};

int dr[] = { 0, 0, 0, 0, 1, -1 };
int dc[] = { 0, 0, 1, -1, 0, 0 };
int dh[] = { 1, -1, 0, 0, 0, 0 };

int main(){
	int r, c, h;
	scanf("%d %d %d", &c, &r, &h);

	queue <ele> q;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < r; j++){
			for (int k = 0; k < c; k++){
				scanf("%d", &chk[i][j][k]);
				if (chk[i][j][k] > 0){
					q.emplace(i, j, k);
				}
			}
		}
	}

	while (!q.empty()){
		ele pp = q.front(); q.pop();
		for (int i = 0; i < 6; i++){
			ele psh = ele(pp.h + dh[i], pp.r + dr[i], pp.c + dc[i]);
			if (psh.h < 0 || psh.h >= h || psh.r < 0 || psh.r >= r || psh.c < 0 || psh.c >= c)continue;
			if (chk[psh.h][psh.r][psh.c] == 0){
				q.emplace(psh);
				chk[psh.h][psh.r][psh.c] = chk[pp.h][pp.r][pp.c] + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < r; j++){
			for (int k = 0; k < c; k++){
				if (chk[i][j][k] == 0)ans = -1;
				else if (chk[i][j][k] > 0){
					if (ans == -1)continue;
					ans = max(ans, chk[i][j][k] - 1);
				}
			}
		}
	}

	printf("%d\n", ans);
}