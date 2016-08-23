#include <stdio.h>
#include <algorithm>

using namespace std;

#define mod 1000000000

int v[1000003] = {0, 1};

int main(){

	for(int i=2; i<=1000000; i++)v[i] = (v[i-1] + v[i-2]) % mod;

	int x;
	scanf("%d", &x);

	if(x > 0){
		printf("1\n%d\n", v[x]);
	}else if(x == 0){
		printf("0\n0");
	}else{
		x *= -1;
		if(x&1)printf("1");
		else
			printf("-1");
		printf("\n%d", v[x]);

	}

}
