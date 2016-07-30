#include <stdio.h>
#include <algorithm>
#define ll long long
#define MAX 1000000007

using namespace std;

ll d[2000] = { 0, 1 };
int top = 0;

int main(){
	ll two = 1;
	for (ll i = 0;; i++){
		if (two > MAX)break;
		ll three = 1;
		for (ll j = 0;; j++){
			if (two*three > MAX)break;
			ll five = 1;
			for (ll k = 0;; k++){
				if (two*three*five > MAX)break;
				d[++top] = two * three * five;
				five *= 5;
			}
			three *= 3;
		}
		two *= 2;
	}

	sort(d, d + top + 1);

	int n;
	while (scanf("%d", &n) == 1 && n){
		printf("%d\n", d[n]);
	}
}