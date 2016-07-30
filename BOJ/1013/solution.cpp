#include <stdio.h>
#include <string.h>

int fa[10][2];
char str[203];

int main(){

	for (int i = 0; i < 10; i++)for (int j = 0; j < 2; j++)fa[i][j] = -1; // is noise;

	fa[0][0] = 1;
	fa[1][1] = 3;
	fa[3][0] = 1;
	fa[3][1] = 2;

	fa[0][1] = 2;
	fa[2][0] = 4;
	fa[4][0] = 5;
	fa[5][0] = 5;
	fa[5][1] = 6;
	fa[6][0] = 1;
	fa[6][1] = 7;
	fa[7][1] = 7;
	fa[7][0] = 8;
	fa[8][0] = 5;
	fa[8][1] = 3;

	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%s", str);

		int s = strlen(str);
		int c = 0;

		for (int i = 0; i < s; i++){
			int n = str[i] - '0';
			c = fa[c][n];
			if (c == -1)break;
		}

		if (c == 3 || c == 6 || c == 7)printf("YES\n");
		else{
			printf("NO\n");
		}
	}
}