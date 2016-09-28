#include <stdio.h>

int output[303][303];

int main()
{
	int n, num = 1;

	scanf("%d", &n);

	for(int i=0; i<n; i++)for(int j=0; j<n; j++)output[i][j] = 0;

	if(n&1){

		int row = 0, col = n/2;

		int pre_row, pre_col;

		output[row][col] = 1;

		while(num != n*n){

			if(row == 0 && col == n-1){
				row = n-1;
				col = 0;
			}
			else if(row == 0 && col != n-1){
				row = n-1;
				col += 1;
			}
			else if(row != 0 && col == n-1){
				row -= 1;
				col = 0;
			}
			else{
				row -= 1;
				col += 1;
			}

			if(output[row][col]){
				pre_row += 1;
				row = pre_row;
				col = pre_col;
			}
			num += 1;
			pre_row = row, pre_col = col;
			output[row][col] = num;

		}

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("%d ", output[i][j]);
			}
			puts("");
		}
	}

}
