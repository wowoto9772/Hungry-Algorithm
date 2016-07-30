#include <stdio.h>

#include <queue>

using namespace std;

class ele{
public:
	int r, c;
	ele(){}
	ele(int a, int b){ r = a, c = b; }
};

bool chk[53][53];
int a[53][53];

int dr[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main(){

	int r, c;
	while (scanf("%d %d", &c, &r) == 2){

		if (!r && !c)break;

		for (int i = 0; i < r; i++)for (int j = 0; j < c; j++){
			scanf("%d", &a[i][j]);
			chk[i][j] = false;
		}

		int ans = 0;

		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){

				if (chk[i][j] || !a[i][j])continue;

				ans++;

				queue <ele> q;
				q.emplace(i, j);
				chk[i][j] = true;

				while (!q.empty()){
					ele f = q.front(); q.pop();
					for (int k = 0; k < 8; k++){
						ele g = { f.r + dr[k], f.c + dc[k] };
						if (g.r >= r || g.c >= c || g.r < 0 || g.c < 0)continue;
						if (chk[g.r][g.c] || !a[g.r][g.c])continue;
						chk[g.r][g.c] = true;
						q.emplace(g);
					}
				}

			}
		}

		printf("%d\n", ans);
	}
}