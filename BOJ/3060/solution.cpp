#include <stdio.h>

#define ll long long

ll e[2][7];

int dp[] = {1, -1};

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		int m;
		scanf("%d", &m);

		ll w = 0;

		for(int i=1; i<=6; i++){
			scanf("%lld", &e[0][i]);
			w += e[0][i];
		}

		if(w <= m){
			for(int i=2;;i++){

				int p = i&1;
				int c = 1^p;

				ll flg = 0;

				for(int j=1; j<=6; j++){

					e[c][j] = e[p][j];
					
					for(int k=0; k<2; k++){
						int aj = j + dp[k];
						if(aj == 0)aj = 6;
						else if(aj == 7)aj = 1;

						e[c][j] += e[p][aj];
					}

					int x = j + 3;

					if(x >= 7)x -= 6;

					e[c][j] += e[p][x];

					flg += e[c][j];
				}

				if(flg <= m)continue;
				else{
					printf("%d\n", i);
					break;
				}
			}
		}else{
			printf("1\n");
		}

	}

}
