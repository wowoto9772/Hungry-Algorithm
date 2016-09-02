#include <stdio.h>

#include <algorithm>

using namespace std;

int p[13];

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	int ends = (1<<n)-1;

	for(int i=0; i<m; i++){

		int x;
		scanf("%d", &x);

		while(x--){

			int y;
			scanf("%d", &y);

			y--;

			p[i] |= (1<<y);

		}
			
	}

	int ans = m+1;

	for(int i=1; i<(1<<m); i++){

		int c = 0, d = 0;

		for(int j=0; j<m; j++){

			if(i & (1<<j))c++, d |= p[j];

		}

		if(d == ends)ans = min(ans, c);

	}

	if(ans == m+1)ans = -1;

	printf("%d\n", ans);

}
