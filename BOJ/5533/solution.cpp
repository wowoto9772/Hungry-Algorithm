#include <stdio.h>

int e[203][4];

int main(){

	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		for(int j=1; j<=3; j++){
			scanf("%d", &e[i][j]);
		}	
	}

	for(int i=1; i<=n; i++){
		int v = 0;
		for(int j=1; j<=3; j++){
			bool flag = false;
			for(int k=1; k<=n; k++){
				if(k == i)continue;
				if(e[k][j] == e[i][j])flag = true;
			}
			if(!flag)v += e[i][j];
		}
		printf("%d\n", v);
	}

}

