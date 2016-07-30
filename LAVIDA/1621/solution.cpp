#include <stdio.h>
#include <math.h>
#include <memory.h>

#define MOD 1000000007

long long M[32][32][32];
long long C[32][32];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		memset(C, 0, sizeof(C));
		memset(M, 0, sizeof(M));

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				scanf("%lld", &M[0][i][j]);
			}
			C[i][i] = 1;
		}

		if (m){

			int lim = log((double)m) / log((double)2);

			for (int a = 1; a <= lim; a++){
				for (int i = 1; i <= n; i++){
					for (int j = 1; j <= n; j++){
						for (int k = 1; k <= n; k++){
							M[a][i][j] += M[a - 1][i][k] * M[a - 1][k][j];
							M[a][i][j] %= MOD;
						}
					}
				}
			}

			for (int a = lim; a >= 0; a--){
				if (m >= 1 << a){
					m -= 1 << a;

					long long tC[32][32] = { 0 };

					for (int i = 1; i <= n; i++){
						for (int j = 1; j <= n; j++){
							for (int k = 1; k <= n; k++){
								tC[i][j] += M[a][i][k] * C[k][j];
								tC[i][j] %= MOD;
							}
						}
					}

					for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)C[i][j] = tC[i][j];
				}
			}
		}

		for (int i = 1; i <= n; i++){
			for (int j = 1; j < n; j++){
				printf("%lld ", C[i][j]);
			}printf("%lld\n", C[i][n]);
		}
	}
}