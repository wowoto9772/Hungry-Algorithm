#include <stdio.h>

#include <math.h>

const double pi = acos(-1.0);

int main(){

	int t;
	scanf("%d", &t);

	int tc = 0;

	while(t--){

		int r, v;
		scanf("%d %d", &r, &v);

		printf("Case %d: %.8lf\n", ++tc, (r*pi/2.0) / (double)v);

	}

}
