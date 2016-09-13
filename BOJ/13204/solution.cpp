#include <stdio.h>

#include <algorithm>

#define ll long long

using namespace std;

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		int a, b;
		scanf("%d.%d", &a, &b);

		int p = a * 1000 + b;

		ll ley = p * 10 - 5;
		ll riy = p * 10 + 5;

		for(ll i=1; i<=100000; i++){

			ll q = ley * i;

			ll l = q / 1000000 + ((q % 1000000) ? 1 : 0);

			q = riy * i;

			ll r = q / 1000000 + ((q % 1000000) ? 1 : 0);

			if(l < r){

				printf("%lld\n", i);
				break;
				
			}
			
		}

	}

}
