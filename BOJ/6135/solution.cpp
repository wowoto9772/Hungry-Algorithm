#include <stdio.h>
#include <limits.h>

#include <algorithm>

using namespace std;

int d[303][303];

int main(){

	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)d[i][j] = INT_MAX;
		d[i][i] = 0;
	}

	for(int i=1; i<=m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if(d[a][b] > c)d[a][b] = c;
	}

	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if((d[i][k]|d[k][j]) == INT_MAX)continue;
				d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
			}
		}
	}

	for(int i=1; i<=q; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		if(d[a][b] == INT_MAX)printf("-1\n");
		else{
			printf("%d\n", d[a][b]);
		}
	}

}
