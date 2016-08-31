#include <stdio.h>
#include <algorithm>

using namespace std;

int e[503];

int main(){

	int n;
	scanf("%d", &n);

	int y = 0;

	for(int i=1; i<=n; i++){
		scanf("%d", &e[i]);
		y += e[i];
	}

	sort(e+1, e+1+n);

	printf("%.7lf\n", (double)y/n);

	if(n&1)printf("%d.0000000\n", e[(n+1)/2]);
	else{
		printf("%.7lf\n", (e[n/2] + e[n/2+1]) / 2.0);
	}

}
