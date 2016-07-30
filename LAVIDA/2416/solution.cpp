#include <stdio.h>

int A(int a){ return a < -a ? -a : a; }

int z[1003];

int main()
{
	int n;
	scanf("%d", &n);

	int c = 0;

	for (int i = 1; i <= n; i++){
		int x, y, r;
		scanf("%d %d %d", &x, &y, &r);
		x = A(x), y = A(y); 
		if (x <= 1000){
			if (y - r < 1000){
				z[c++] = i;
			}
		}
		else if (y <= 1000){
			if (x - r < 1000){
				z[c++] = i;
			}
		}
		else{
			int k = (x - 1000)*(x - 1000) + (y - 1000)*(y - 1000);
			if(k < r*r)z[c++] = i;
		}
	}
	printf("%d\n", c);
	for (int i = 0; i < c; i++)printf("%d\n", z[i]);
}