#include <cstdio>
#include <queue>

using namespace std;

int e[253][253];
int dr[] = { 0, 0, -1, -1, -1, 1, 1, 1 };
int dc[] = { -1, 1, -1, 0, 1, -1, 0, 1 };

int main(){

	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)for (int j = 0; j < c; j++)scanf("%d", &e[i][j]);

	int m = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (e[i][j]){
				m++;
				queue < pair <int, int> > q;
				q.emplace(i, j);

				while (!q.empty()){
					auto &f = q.front(); q.pop();
					for (int k = 0; k < 8; k++){
						pair <int,int> g = { f.first + dr[k], f.second + dc[k] };
						if (g.first < 0 || g.first >= r)continue;
						if (g.second < 0 || g.second >= c)continue;
						if (e[g.first][g.second]){
							q.emplace(g);
							e[g.first][g.second] = 0;
						}
					}
				}
			}
		}
	}

	printf("%d\n", m);

}