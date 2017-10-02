#include <cstdio>

using namespace std;

int dr[] = { 0, 1, 0, -1 };
int dc[] = { -1, 0, 1, 0 };

char str[405][403];

int main(){

	int n;
	scanf("%d", &n);

	if (n == 1){
		printf("*");
		return 0;
	}

	int d = 0;

	int C = ((n - 1) << 2) + 1;
	int R = C + 2;

	for (int i = 0; i <= R + 1; i++)for (int j = 0; j <= C + 1; j++){
		if (i == 0 || i == R + 1 || j == 0 || j == C + 1)str[i][j] = -1;
		else
			str[i][j] = ' ';
	}
			
	int r = 1, c = C;
	str[r][c] = '*';

	while (true){
		int nr = r + dr[d], nc = c + dc[d];
		if (str[nr][nc] == -1 || str[r + 2*dr[d]][c + 2*dc[d]] == '*'){
			d++;
			d %= 4;
			if (str[r + 2*dr[d]][c + 2*dc[d]] == '*')break;
		}
		else{
			str[nr][nc] = '*';
			r = nr, c = nc;
		}
	}

	for (int i = 1; i <= R; i++){
		if (i == 2){
			puts("*");
			continue;
		}
		for (int j = 1; j <= C; j++){
			printf("%c", str[i][j]);
		}puts("");
	}

}