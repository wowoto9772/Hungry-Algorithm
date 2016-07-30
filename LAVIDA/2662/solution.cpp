#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int I[103][103], J[103][103];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int r, c;
		scanf("%d %d", &r, &c);

		int x = 0;
		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= c; j++){
				scanf("%d", &I[i][j]);
				J[i][j] = I[i][j];
				if (I[i][j] == 1)x++;
			}
		}

		int ans = 0;
		while (x){
			for (int i = 1; i <= r; i++){
				for (int j = 1; j <= c; j++){
					if (I[i][j] == 0){
						if (J[i][j + 1]){
							x--;
							J[i][j + 1] = 0;
						}
						if (J[i][j - 1]){
							x--;
							J[i][j - 1] = 0;
						}
						if (J[i - 1][j]){
							x--;
							J[i - 1][j] = 0;
						}
						if (J[i + 1][j]){
							x--;
							J[i + 1][j] = 0;
						}
					}
				}
			}

			if (x){
				for (int i = 1; i <= r; i++)
					for (int j = 1; j <= c; j++)
						I[i][j] = J[i][j];
			}
			ans++;
		}

		printf("%d\n", ans);
	}
}