#include <stdio.h>

int rat[1003] = {-1, };

int main(){

	int n, t;
	scanf("%d %d", &n, &t);
	
	for(int i=1; i<=n; i++)scanf("%d", &rat[i]);

	for(int i=1; i<=t; i++){
		
		int x = 0;

		for(int j=1; j<=n; j++){
			if(rat[x] < rat[j]){
				x = j;
			}
		}

		printf("%d\n", x);

		int rem = rat[x] % (n-1);

		for(int j=1; j<=n; j++){
			if(x == j){
				continue;
			}
			rat[j] += rat[x] / (n-1);
			if(rem){
				rem--;
				rat[j]++;
			}
		}

		rat[x] = 0;

	}

}
