#include <stdio.h>
#include <memory.h>

char str[13][13];
int g[13][13], s[13][13], h[10][13];
int y[10][10] = {
	{ 0, 0, 0, 1, 1, 1, 2, 2, 2 },
	{ 0, 0, 0, 1, 1, 1, 2, 2, 2 },
	{ 0, 0, 0, 1, 1, 1, 2, 2, 2 } ,
	{ 3, 3, 3, 4, 4, 4, 5, 5, 5 },
	{ 3, 3, 3, 4, 4, 4, 5, 5, 5 },
	{ 3, 3, 3, 4, 4, 4, 5, 5, 5 },
	{ 6, 6, 6, 7, 7, 7, 8, 8, 9 },
	{ 6, 6, 6, 7, 7, 7, 8, 8, 9 },
	{ 6, 6, 6, 7, 7, 7, 8, 8, 9 }
};

bool sudoku(int i, int j) {
	if (j == 9)return sudoku(i + 1, 0);
	else if (i == 9) {
		for (int a = 0; a < 9; a++) {
			for (int b = 0; b < 9; b++) {
				printf("%c", str[a][b]);
			}printf("\n");
		}
		return true;
	}
	else if (str[i][j] != '0')return sudoku(i, j + 1);
	else {
		for (int a = 1; a <= 9; a++) {
			if (g[i][a] || s[j][a])continue;
			else if (h[y[i][j]][a])continue;
			else {
				str[i][j] = a + '0';
				g[i][a] = 1;
				s[j][a] = 1;
				h[y[i][j]][a] = 1;
				if (sudoku(i, j + 1))return true;
				g[i][a] = 0;
				s[j][a] = 0;
				h[y[i][j]][a] = 0;
			}
		}
		str[i][j] = '0';
	}
	return false;
}

int main()
{

	for (int i = 0; i < 9; i++) {
		
		scanf("%s", str[i]);

		for (int j = 0; j < 9; j++) {

			if (str[i][j] != '0') {

				int what = str[i][j] - '0';
				g[i][what] = 1;
				s[j][what] = 1;
				h[y[i][j]][what] = 1;
				
			}

		}
	}
	sudoku(0, 0);
}