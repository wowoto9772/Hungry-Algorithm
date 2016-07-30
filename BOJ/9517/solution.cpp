#include <stdio.h>

int main(){
	int c;
	scanf("%d", &c);

	int n;
	scanf("%d", &n);

	int m = 0;

	for (int i = 1; i <= n; i++){
		int t;
		char a;
		scanf(" %d %c", &t, &a);

		m += t;

		if (m >= 210)continue;

		if (m < 210){
			if (a == 'T'){
				c++;
				if (c == 9)c = 1;
			}
			else
				continue;
		}
	}
	
	printf("%d\n", c);
}