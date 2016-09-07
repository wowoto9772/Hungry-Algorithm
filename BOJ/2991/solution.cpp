#include <stdio.h>

int main(){

	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	for(int i=1; i<=3; i++){
		int x;
		scanf("%d", &x);

		x--;

		int y = 0;

		if(x % (a+b) < a)y++;
		if(x % (c+d) < c)y++;

		printf("%d\n", y);
	}

}
