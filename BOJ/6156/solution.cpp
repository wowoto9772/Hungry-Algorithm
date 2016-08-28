#include <stdio.h>

bool win[103][103];

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=m; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		win[a][b] = true;
	}

	for(int i=1; i<=n; i++)win[i][i] = true;

	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(win[i][k] && win[k][j])win[i][j] = true;
			}
		}
	}

	int ans = 0;

	for(int i=1; i<=n; i++){
		bool flag = true;
		for(int j=1; j<=n && flag; j++){
			flag &= (win[i][j] | win[j][i]);
		}
		if(flag)ans++;
	}

	printf("%d\n", ans);

}
