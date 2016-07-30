#include <stdio.h>

int I[12][12];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n = 9;
		for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)scanf("%d", &I[i][j]);

		bool f = false;

		for (int i = 1; !f && i <= n; i++){
			bool H[10] = { 0 }, W[10] = { 0 };
			for (int j = 1; j <= n; j++){
				H[I[i][j]] = true;
				W[I[j][i]] = true;
			}
			for (int j = 1; j <= n; j++){
				if (!H[j] || !W[j])f = true;
			}
		}

		for (int i = 1; !f && i <= 3; i++){
			for (int j = 1; !f && j <= 3; j++){
				bool R[10] = { 0 };
				for (int k = (i - 1) / 3 * 3 + 1; k <= (i - 1) / 3 * 3 + 3; k++){
					for (int l = (j - 1) / 3 * 3 + 1; l <= (j - 1) / 3 * 3 + 3; l++){
						R[I[k][l]] = true;
					}
				}
				for (int k = 1; k <= n; k++){
					if (!R[k])f = true;
				}
			}
		}

		if (f)printf("No\n");
		else
			printf("Yes\n");
	}
}