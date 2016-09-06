#include <stdio.h>

#include <limits.h>

#include <algorithm>

using namespace std;

int p[50003];

int main(){

	int n, k;
	scanf("%d %d", &n, &k);

	for(int i=1; i<=n; i++){
		scanf("%d", &p[i]);
	}

	sort(p+1, p+1+n);

	int ans = INT_MAX;

	int l = 0, r = 1000000000, m;

	while(l <= r){

		m = (l+r) / 2;

		int c = 1;

		int x = 1;
		
		for(int i=2; i<=n; i++){
			if(p[i] - p[x] <= (m<<1)){}
			else{
				c++;
				x = i;
			}
		}

		if(c <= k){
			ans = min(ans, m);
			r = m - 1;
		}else{
			l = m + 1;
		}

	}

	printf("%d\n", ans);

}
