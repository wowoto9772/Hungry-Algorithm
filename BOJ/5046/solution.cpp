#include <stdio.h>

#include <algorithm>

using namespace std;

int main(){

	int n, b, h, w;
	scanf("%d %d %d %d", &n, &b, &h, &w);

	int ans = -1;

	for(int i=1; i<=h; i++){
		int p;
		scanf("%d", &p);

		for(int j=0; j<w; j++){
			int k;
			scanf("%d", &k);
			if(n <= k){
				if(n*p > b)continue;
				if(ans == -1)ans = n * p;
				else
					ans = min(ans, n*p);
			}
		}
	}

	if(ans == -1)printf("stay home");
	else{
		printf("%d", ans);
	}

}
