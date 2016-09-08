#include <stdio.h>

#include <algorithm>

using namespace std;

int s[23];

int main(){

	int t;
	scanf("%d", &t);

	int tc = 0;

	while(t--){

		int n, m;
		scanf("%d %d", &n, &m);

		for(int i=0; i<n; i++){
			scanf("%d", &s[i]);
		}

		sort(s, s+n);

		int lst = 0, tot = 0, cur = 0, solv = 0;

		for(int i=0; i<n; i++){
			if(cur + s[i] <= m){
				cur += s[i];
				tot += cur;
				lst = cur;
				solv++;
			}else{
				break;
			}
		}

		printf("Case %d: %d %d %d\n", ++tc, solv, lst, tot);

	}

}
