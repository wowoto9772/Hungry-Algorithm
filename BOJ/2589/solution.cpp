#include <stdio.h>

#include <queue>
#include <algorithm>

using namespace std;

class ele{
public:
	int r, c;
	ele(){}
	ele(int a, int b){ r = a, c = b; }
};

char str[53][53];
bool chk[53][53];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main(){

	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)scanf("%s", str[i]);

	int ans = 0;

	for (int i = 0; i < r; i++){

		for (int j = 0; j < c; j++){

			if (str[i][j] == 'L'){

				for (int a = 0; a < r; a++)for (int b = 0; b < c; b++)chk[a][b] = false;

				chk[i][j] = true;

				queue <ele> q;
				queue <int> w;

				q.emplace(i, j);
				w.push(0);

				int tmp = 0;

				while (!q.empty()){

					int e = w.front(); w.pop();
					ele f = q.front(); q.pop();

					tmp = max(tmp, e);
					1;


					for (int k = 0; k < 4; k++){

						ele g = ele(f.r + dr[k], f.c + dc[k]);

						if (g.r < 0 || g.c < 0 || g.r >= r || g.c >= c)continue;

						if (!chk[g.r][g.c] && str[g.r][g.c] == 'L'){
							chk[g.r][g.c] = true;
							q.emplace(g);
							w.push(e + 1);
						}



					}

				}


				ans = max(ans, tmp);

			}
		}
	}

	printf("%d\n", ans);

}