#include <stdio.h>

#define ll long long

int c[1<<18];

int binary_code(ll v){

	int ret = 0;

	int x = 0;
	
	while(v){

		int f = v%10;

		if(f&1)ret += 1<<x;

		x++;

		v /= 10;
		
	}

	return ret;

}

int main(){

	int t;
	scanf("%d", &t);
	
	while(t--){

		char x;
		ll v;

		scanf(" %c %lld", &x, &v);

		if(x == '+'){
			c[binary_code(v)]++;
		}
		else if(x == '-'){
			c[binary_code(v)]--;
		}else{
			printf("%d\n", c[binary_code(v)]);
		}


	}

}
