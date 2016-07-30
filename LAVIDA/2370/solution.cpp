#include <stdio.h>
#include <stdlib.h>

int I[23];

double FA(double a){ return a < -a ? -a : a; }

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		double a = 0;
		int b = 0;

		for (int i = 1; i <= n; i++){
			scanf("%d", &I[i]);
			a += I[i];
			b = b < I[i] ? I[i] : b;
		}

		a /= n;

		double c = FA(a - I[1]);
		int d = 1;

		for (int i = 2; i <= n; i++){
			double e = FA(a - I[i]);
			if (e < c){
				d = i;
				c = e;
			}
			else if (e == c){
				if (I[d] < I[i])d = i;
			}
		}

		printf("%d %d\n", b, I[d]);
	}
}