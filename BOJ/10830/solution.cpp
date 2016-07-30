#include <stdio.h>

#define ll long long
#define MOD 1000

int M[63][6][6];
int C[6][6];

int main()
{

	int n;
	ll m;
	scanf("%d %lld", &n, &m);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", &M[0][i][j]);
		}
		C[i][i] = 1;
	}

	if (m){

		for (int a = 0; m; a++){
			if (m & 1){

				int tC[6][6] = { 0 };

				for (int i = 1; i <= n; i++){
					for (int j = 1; j <= n; j++){
						for (int k = 1; k <= n; k++){
							tC[i][j] += M[a][i][k] * C[k][j];
						}
						tC[i][j] %= MOD;
					}
				}



				for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)C[i][j] = tC[i][j];
			}

			m /= 2;

			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					for (int k = 1; k <= n; k++){
						M[a + 1][i][j] += M[a][i][k] * M[a][k][j];
					}
					M[a + 1][i][j] %= MOD;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j < n; j++){
			printf("%d ", C[i][j]);
		}printf("%d\n", C[i][n]);
	}
}