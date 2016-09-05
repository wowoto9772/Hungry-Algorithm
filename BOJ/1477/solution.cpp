#include <stdio.h>

#include <algorithm>

using namespace std;

int p[103];

int main(){

	int n, k, L;

	scanf("%d %d %d", &n, &k, &L);
	
	for(int i=1; i<=n; i++){

		scanf("%d", &p[i]);

	}

	sort(p+1, p+1+n);

	p[n+1] = L;

	int l = 1, r = 1000, m;

	int ans = r;

	while(l <= r){

		m = (l+r) / 2;

		int c = 0;

		int s = p[0];

		for(int i=1; i<=n+1 && c <= k;){
			
			if(p[i] - s > m){
				s += m;
				c++;
			}else{
				s = p[i];
				i++;
			}

		}

		if(c == k+1)l = m + 1;
		else{
			ans = min(ans, m);
			r = m - 1;
		}

	}

	printf("%d\n", ans);

}
