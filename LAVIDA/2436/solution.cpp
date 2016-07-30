#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

class need{
public:
	int sr, sc, er, ec;
};

int R, C, K;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
char str[9][9];
bool chk[9][9];

vector <need> X;
int ans;

void Link(int r, int c, int k, int m){
	chk[r][c] = true;
	if (r == X[k].er && c == X[k].ec){
		if (k+1 == K){
			if (m == 1)ans++;
			chk[r][c] = false;
			return;
		}
		else{
			k++;
			Link(X[k].sr, X[k].sc, k, m - 1);
			chk[r][c] = false;
			return;
		}
	}
	for (int i = 0; i < 4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nr >= R)continue;
		if (nc < 0 || nc >= C)continue;
		if (chk[nr][nc])continue;
		if (str[nr][nc] >= 'A' && str[nr][nc] <= 'Z'){
			if (X[k].er != nr || X[k].ec != nc){
				continue;
			}
		}
		Link(nr, nc, k, m - 1);
	}
	chk[r][c] = false;
}

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d %d", &R, &C, &K);
		for (int i = 0; i < R; i++)scanf("%s", str[i]);

		bool cha['Z' + 3] = { 0 };

		need psh;

		for (int i = 0; i < R; i++){
			for (int j = 0; j < C; j++){
				if (str[i][j] >= 'A' && str[i][j] <= 'Z'){
					if (cha[str[i][j]])continue;
					cha[str[i][j]] = true;

					bool sel = false;

					for (int i2 = 0; !sel && i2 < R; i2++){
						for (int j2 = 0; !sel && j2 < C; j2++){
							if (i2 == i && j2 == j)continue;
							if (str[i][j] == str[i2][j2]){
								psh = { i, j, i2, j2 };
								X.push_back(psh);
								sel = true;
							}
						}
					}
				}
			}
		}

		ans = 0;
		Link(X[0].sr, X[0].sc, 0, R*C);

		printf("%d\n", ans);

		X.clear();
	}
}