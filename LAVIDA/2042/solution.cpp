#include <stdio.h>
#include <memory.h>
#define Min(a, b) a < b ? a : b
#define Max(a, b) a < b ? b : a
#define M 987654321

int f[1002], d[1002];

int x[20002], y[20002]; // 20 * 1000

int main()
{
	int N, K, L;
	while (scanf("%d %d %d", &N, &K, &L) == 3 && N){

		for (int i = 1; i <= N; i++){
			scanf("%d %d", &f[i], &d[i]);
		}

		memset(x, 0x3f, sizeof(x));
		x[0] = 0;
		for (int i = 1; i <= N; i++){
			if (i % 2)memset(y, 0x3f, sizeof(y));
			else
				memset(x, 0x3f, sizeof(x));
			for (int j = 0; j <= N * 20; j++){
				if (i % 2){
					if (x[j] < M){
						// no ride
						int c = Max(x[j] - K, 0);
						y[j] = Min(y[j], c);
						// ride
						if (j + f[i] <= N * 20 && x[j] + d[i] <= L){
							y[j + f[i]] = Min(y[j + f[i]], x[j] + d[i]);
						}
					}
				}
				else{
					if (y[j] < M){
						// no ride
						int c = Max(y[j] - K, 0);
						x[j] = Min(x[j], c);
						// ride
						if (j + f[i] <= N * 20 && y[j] + d[i] <= L){
							x[j + f[i]] = Min(x[j + f[i]], y[j] + d[i]);
						}
					}
				}
			}
		}

		for (int i = N * 20; i >= 0; i--){
			if (x[i] < M || y[i] < M){
				printf("%d\n", i);
				break;
			}
		}
	}
}
