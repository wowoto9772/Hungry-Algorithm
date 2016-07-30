#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

char str[53][53];

int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
int chk[53][53] = { 0 };

int R, C, x;
char X;

bool E;

void S(int i, int j){
	bool f = false;
	for (int k = 0; k < 4; k++){
		int ni = i + dr[k], nj = j + dc[k];
		if (0 <= ni && ni < R && 0 <= nj && nj < C){
			if (!chk[ni][nj] && str[ni][nj] == X){
				chk[ni][nj] = ++x;
				if (!E)S(ni, nj);
				f = true;
			}

		}
	}

	if (!f){

		for (int k = 0; k < 4; k++){
			int ni = i + dr[k], nj = j + dc[k];
			if (0 <= ni && ni < R && 0 <= nj && nj < C){
				if (chk[ni][nj] && str[ni][nj] == X){
					if (abs(chk[i][j] - chk[ni][nj]) >= 3){
						E = true;
					}
				}
			}
		}
	}
}

int main()
{
	freopen("large_dat6.in", "r", stdin);
	freopen("large_dat6.out", "w", stdout);
	while (scanf("%d %d", &R, &C) == 2 && R && C){

		for (int i = 0; i < R; i++)scanf("%s", str[i]);

		memset(chk, 0, sizeof(chk));

		for (int i = 0; !E && i < R; i++){
			for (int j = 0; !E && j < C; j++){
				if (!chk[i][j]){
					X = str[i][j];
					x = 1;
					chk[i][j] = x;
					S(i, j);
				}
			}

		}

		if (!E)printf("alone\n");
		else
			printf("together\n");

	}
}