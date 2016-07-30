#include <stdio.h>

int main(){

	int a, b, c, d;

	for (int i = 0; i < 3; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int x = a + b + c + d;

		if (!x)printf("D\n");
		else if (x == 4)printf("E\n");
		else{
			printf("%c\n", 'A' + (3 - x));
		}
	}
}