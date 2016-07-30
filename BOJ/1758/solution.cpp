#include <stdio.h>
#include <algorithm>
#define ll long long

using namespace std;

int p[100003];

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}

	sort(p, p + n);

	int c = 0;
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--){
		if (p[i] + c > 0)ans += p[i] + c;
		c--;
	}

	printf("%lld\n", ans);

}