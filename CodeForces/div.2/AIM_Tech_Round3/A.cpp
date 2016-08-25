#include <stdio.h>

int main(){

	int n, b, d;
	scanf("%d %d %d", &n, &b, &d);

	int x = 0;
	int y = 0;

	for(int i=1; i<=n; i++){
		int a;
		scanf("%d", &a);
		if(a > b)continue;
		x += a;
		if(x > d){
			y++;
			x = 0;

		}
	}	

	printf("%d\n", y);

}
