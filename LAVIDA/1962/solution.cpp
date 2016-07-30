//#include <stdio.h>
//#include <memory.h>
//
//int nx[10][10], ny[10][10];
//char str[13][13];
//bool g[13][13], s[13][13], h[4][4][13];
//
//bool sudoku(int i, int j){
//	if (i == 9){
//		for (int a = 0; a < 9; a++)printf("%s\n", str[a]);
//		return true;
//	}
//	for (int a = 1; a <= 9; a++){
//		if (!h[i/3][j/3][a] && !g[i][a] && !s[j][a]){
//			str[i][j] = a + '0';
//			g[i][a] = s[j][a] = h[i/3][j/3][a] = true;
//			if (sudoku(nx[i][j], ny[i][j]))return true;
//			g[i][a] = s[j][a] = h[i / 3][j / 3][a] = false;
//		}
//	}
//	return false;
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int sx = -1, sy = -1;
//		int a, b;
//
//		memset(g, 0, sizeof(g));
//		memset(s, 0, sizeof(s));
//		memset(h, 0, sizeof(h));
//
//		for (int i = 0; i < 9; i++){
//			scanf("%s", str[i]);
//			for (int j = 0; j < 9; j++){
//				if (str[i][j] == '0'){
//					if (sx == sy && sx == -1){
//						a = i, b = j;
//						nx[i][j] = i, ny[i][j] = j;
//						sx = i, sy = j;
//					}
//					else{
//						nx[sx][sy] = i, ny[sx][sy] = j;
//						nx[i][j] = i, ny[i][j] = j;
//						sx = i, sy = j;
//					}
//				}
//				else{
//					int what = str[i][j] - '0';
//					g[i][what] = s[j][what] = h[i / 3][j / 3][what] = true;
//				}
//			}
//		}
//		nx[sx][sy] = 9, ny[sx][sy] = 0;
//		sudoku(a, b);
//	}
//}

/*
1
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
*/
//#include <stdio.h>
//#include <memory.h>
//
//char str[13][13];
//bool g[13][13], s[13][13], h[13][13];
//
//bool sudoku(int i, int j){
//	if (j == 9)return sudoku(i+1, 0);
//	else if (i == 9){
//		for (int a = 0; a < 9; a++)printf("%s\n", str[a]);
//		return true;
//	}
//	else if (str[i][j] != '0')return sudoku(i, j + 1);
//	else{
//		for (int a = 1; a <= 9; a++){
//			if (!h[i / 3 * 3 + j/3][a] && !g[i][a] && !s[j][a]){
//				str[i][j] = a + '0';
//				g[i][a] = s[j][a] = h[i / 3 * 3 + j/3][a] = true;
//				if (sudoku(i, j+1))return true;
//				g[i][a] = s[j][a] = h[i / 3 * 3 + j/3][a] = false;
//			}
//		}
//		str[i][j] = '0';
//	}
//	return false;
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		memset(g, 0, sizeof(g));
//		memset(s, 0, sizeof(s));
//		memset(h, 0, sizeof(h));
//
//		for (int i = 0; i < 9; i++){
//			scanf("%s", str[i]);
//			for (int j = 0; j < 9; j++){
//				if(str[i][j] != '0'){
//					int what = str[i][j] - '0';
//					g[i][what] = s[j][what] = h[i/3*3+j/3][what] = true;
//				}
//			}
//		}
//		sudoku(0, 0);
//	}
//}

//#include <stdio.h>
//#include <memory.h>
//
//char str[13][13];
//int g[13][13], s[13][13], h[13][13];
//int nx[10][10], ny[10][10];
//
//bool sudoku(int i, int j){
//	if (i == 9){
//		for (int a = 0; a < 9; a++)printf("%s\n", str[a]);
//		return true;
//	}
//	else{
//		for (int a = 1; a <= 9; a++){
//			if (g[i][a])continue;
//			else if (s[j][a])continue;
//			else if (h[i / 3 * 3 + j / 3][a])continue;
//			else{
//				str[i][j] = a + '0';
//				g[i][a] = 1;
//				s[j][a] = 1;
//				h[i / 3 * 3 + j / 3][a] = 1;
//				if (sudoku(nx[i][j], ny[i][j]))return true;
//				g[i][a] = 0;
//				s[j][a] = 0;
//				h[i / 3 * 3 + j / 3][a] = 0;
//			}
//		}
//		str[i][j] = '0';
//	}
//	return false;
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		memset(g, 0, sizeof(g));
//		memset(s, 0, sizeof(s));
//		memset(h, 0, sizeof(h));
//
//		int sx = -1, sy = -1, a, b;
//
//		for (int i = 0; i < 9; i++){
//			scanf("%s", str[i]);
//			for (int j = 0; j < 9; j++){
//				if (str[i][j] == '0'){
//					if (sx == sy && sx == -1){
//						a = i, b = j;
//						nx[i][j] = i, ny[i][j] = j;
//						sx = i, sy = j;
//					}
//					else{
//						nx[sx][sy] = i, ny[sx][sy] = j;
//						nx[i][j] = i, ny[i][j] = j;
//						sx = i, sy = j;
//					}
//				}
//				else if (str[i][j] != '0'){
//					int what = str[i][j] - '0';
//					g[i][what] = 1;
//					s[j][what] = 1;
//					h[i / 3 * 3 + j / 3][what] = 1;
//				}
//			}
//		}
//		nx[sx][sy] = 9;
//		sudoku(a, b);
//	}
//}

#include <stdio.h>
#include <memory.h>

char str[13][13];
int g[13][13], s[13][13], h[10][13];
int y[10][10] = { 
{0, 0, 0, 1, 1, 1, 2, 2, 2},
{0, 0, 0, 1, 1, 1, 2, 2, 2},
{0, 0, 0, 1, 1, 1, 2, 2, 2} ,
{3, 3, 3, 4, 4, 4, 5, 5, 5},
{3, 3, 3, 4, 4, 4, 5, 5, 5},
{3, 3, 3, 4, 4, 4, 5, 5, 5},
{6, 6, 6, 7, 7, 7, 8, 8, 9},
{6, 6, 6, 7, 7, 7, 8, 8, 9},
{6, 6, 6, 7, 7, 7, 8, 8, 9}
};

bool sudoku(int i, int j){
	if (j == 9)return sudoku(i + 1, 0);
	else if (i == 9){
		for (int a = 0; a < 9; a++)printf("%s\n", str[a]);
		return true;
	}
	else if (str[i][j] != '0')return sudoku(i, j + 1);
	else{
		for (int a = 9; a >= 1; a--){
			if (g[i][a] || s[j][a])continue;
			else if (h[y[i][j]][a])continue;
			else{
				str[i][j] = a + '0';
				g[i][a] = 1;
				s[j][a] = 1;
				h[y[i][j]][a] = 1;
				if (sudoku(i, j+1))return true;
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
	int t;
	scanf("%d", &t);

	while (t--){
		memset(g, 0, sizeof(g));
		memset(s, 0, sizeof(s));
		memset(h, 0, sizeof(h));

		for (int i = 0; i < 9; i++){
			scanf("%s", str[i]);
			for (int j = 0; j < 9; j++){
				if (str[i][j] != '0'){
					int what = str[i][j] - '0';
					g[i][what] = 1;
					s[j][what] = 1;
					h[y[i][j]][what] = 1;
				}
			}
		}
		sudoku(0, 0);
	}
}