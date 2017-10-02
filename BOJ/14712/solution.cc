#include <stdio.h>

int r, c;
int cnt;

int e[28][28];

void backTracking(int i, int j){
	if (j == c)backTracking(i + 1, 0);
	else if (i == r){
		cnt++;
	}
	else{
		
		if (i > 0 && j > 0){
			int v = e[i - 1][j - 1] + e[i - 1][j] + e[i][j - 1];
			if (v < 3){
				e[i][j] = 1;
				backTracking(i, j + 1);
			}
		}
		else{
			e[i][j] = 1;
			backTracking(i, j + 1);
		}

		e[i][j] = 0;
		backTracking(i, j + 1);
	}
}

int main(){

	scanf("%d %d", &r, &c);
	backTracking(0, 0);
	printf("%d\n", cnt);

}