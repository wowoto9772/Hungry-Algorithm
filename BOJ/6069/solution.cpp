#include <stdio.h>

bool swc[503];

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=m; i++){
		
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);

		if(t == 0){
			for(int j=a; j<=b; j++){
				swc[j] ^= true;
			}
		}else{
			int c = 0;

			for(int j=a; j<=b; j++){
				c += swc[j];
			}

			printf("%d\n", c);
		}

	}

}
