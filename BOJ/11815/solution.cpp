//#include <stdio.h>
//
//#define ll long long
//
//ll cnt(ll a){
//
//	ll c = 1;
//	for (ll i = 2; i*i <= a; i++){
//		if (a%i)continue;
//		ll k = 0;
//		while (!(a%i)){
//			a /= i;
//			k++;
//		}
//		c *= (k + 1);
//	}
//
//	if (c == 1)return 0; // prime number
//
//	return c % 2;
//
//}
//
//int main(){
//
//	int n;
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++){
//	
//		ll a;
//		scanf("%lld", &a);
//
//		printf("%d ", cnt(a)); // sqrt(n) : Fail
//
//	}
//
//}

#include <stdio.h>
#include <math.h>

#define ll long long

int square(ll a){
	ll b = sqrt((double)a);
	return (b*b == a) ? 1 : 0;
}

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){

		ll a;
		scanf("%lld", &a);

		printf("%d ", square(a));

	}

}