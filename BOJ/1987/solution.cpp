#include <stdio.h>

int ans = 0;
char str[22][22];
bool chk['Z' + 3];
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
int r, c;

void search(int i, int j, int k){
	chk[str[i][j]] = true;

	for (int a = 0; a < 4; a++){
		int ni = i + dr[a];
		int nj = j + dc[a];
		if (ni < 0 || ni >= r)continue;
		if (nj < 0 || nj >= c)continue;
		if (chk[str[ni][nj]])continue;
		search(ni, nj, k + 1);
	}

	if (ans < k)ans = k;

	chk[str[i][j]] = false;
}

int main(){
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)scanf("%s", str[i]);

	search(0, 0, 0);

	printf("%d\n", ans + 1);
}