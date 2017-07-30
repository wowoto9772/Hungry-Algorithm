#include <stdio.h>
#define MAX_INT ((1<<31)-1)

int f[1002], d[1002];
int x[20002], y[20002]; // 20 * 1000

int Min(int a, int b){
    if(a > b)a = b;
    return a;
}

int Max(int a, int b){
    if(a < b)a = b;
    return a;
}

int main()
{
	int N, K, L;
	while (scanf("%d %d %d", &N, &K, &L) == 3){
        if(N+K+L == 0)break;

		for (int i = 1; i<=N; i++){
			scanf("%d %d", &f[i], &d[i]);
		}

        for(int i=0; i<=N*20; i++)x[i] = MAX_INT;
		x[0] = 0;
		for (int i=1; i<=N; i++){
			if (i&1)for(int j=0; j<=N*20; j++)y[j] = MAX_INT;
			else
                for(int j=0; j<=N*20; j++)x[j] = MAX_INT;
                
			for (int j=0; j<=N*20; j++){
				if (i&1){
					if (x[j] != MAX_INT){
						// no ride
						int c = Max(x[j] - K, 0);
						y[j] = Min(y[j], c);
						// ride
						if (j + f[i] <= N*20 && x[j] + d[i] <= L){
							y[j + f[i]] = Min(y[j + f[i]], x[j] + d[i]);
						}
					}
				}
				else{
					if (y[j] != MAX_INT){
						// no ride
						int c = Max(y[j] - K, 0);
						x[j] = Min(x[j], c);
						// ride
						if (j + f[i] <= N*20 && y[j] + d[i] <= L){
							x[j + f[i]] = Min(x[j + f[i]], y[j] + d[i]);
						}
					}
				}
			}
		}

		for (int i=N*20; i>=0; i--){
			if (x[i] != MAX_INT || y[i] != MAX_INT){
				printf("%d\n", i);
				break;
			}
		}
	}
}