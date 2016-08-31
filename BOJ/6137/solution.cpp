#include <stdio.h>

char x[2003];

int n, s;

void ans(int pt){
	printf("%c", x[pt]);
	s++;
	if(!(s%80))printf("\n");
}

int main(){

	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		scanf(" %c", &x[i]);
	}

	int l = 1, r = n;

	while(l <= r){

		if(x[l] > x[r]){
			ans(r--);
		}else if(x[l] < x[r]){
			ans(l++);
		}else{

			int pl = l, pr = r;

			while(pl+1 < pr-1 && x[pl] == x[pr])pl++, pr--;

			if(x[pl] < x[pr])ans(l++);
			else{
				ans(r--);
			}

		}

	}

}
