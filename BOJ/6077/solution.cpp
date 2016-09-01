#include <stdio.h>

int cnt[1000003];
int e[100003];

int main(){

	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		
		scanf("%d", &e[i]);

		cnt[e[i]]++;

	}

	for(int i=1; i<=n; i++){

		int v = e[i];

		int c = cnt[v] - 1;

		if(v != 1)c += cnt[1];

		for(int j=2; j*j <= v && j < v; j++){
			if(v%j)continue;
			c += cnt[j];
			if(j < v/j)c += cnt[v/j];
		}

		printf("%d\n", c);

	}

}

