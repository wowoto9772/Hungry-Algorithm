#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int x, y;
		scanf("%d %d", &x, &y);

		printf("%d %d\n", 2 * y - x, x - y);
		// a + 2*b = x;
		// a + b = y;
	}
}