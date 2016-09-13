#include <stdio.h>

#include <algorithm>

using namespace std;

char str[53][53];

int dist(int a, int b, int x, int y){
	return (a-x)*(a-x) + (b-y)*(b-y);
}

int main(){

	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){

		scanf("%s", str[i]+1);

	}

	int ans = 0;

	for(int i=1; i<=n; i++){

		for(int j=1; j<=n; j++){

			if(str[i][j] == '*')continue;

			int l = ans+1, r = min({n-i, n-j, i-1, j-1}), m;

			while(l <= r){

				m = (l+r) / 2;

				bool pos = true;

				for(int a=1; a<=n && pos; a++){
					for(int b=1; b<=n && pos; b++){
						if(dist(a,b,i,j) <= m*m){
							if(str[a][b] == '*'){
								pos = false;
							}

						}
					}
				}

				if(pos){
					l = m + 1;
					ans = max(ans, m);
				}
				else
					r = m - 1;
			}
		}
	}

	printf("%d\n", ans);

}
