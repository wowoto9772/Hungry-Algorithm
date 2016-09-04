#include <stdio.h>

int c[1003];
int p[1003];

int main(){

	int l, n;
	scanf("%d %d", &l, &n);

	int q = 0, w;

	for(int i=1; i<=n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(q < (b-a+1)){
			q = (b-a+1);
			w = i;
		}
		for(int j=a; j<=b; j++){
			if(!c[j])c[j] = i;
		}
	}

	for(int i=1; i<=l; i++){
		p[c[i]]++;	
	}

	int r = 1;

	for(int i=2; i<=n; i++){
		if(p[r] < p[i])r = i;
	}

	printf("%d\n%d\n", w, r);

}
