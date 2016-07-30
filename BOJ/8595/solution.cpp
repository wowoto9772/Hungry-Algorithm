#include <stdio.h>
#define ll long long

char str[5000003];

int main(){
	int n;
	scanf("%d %s", &n, str);

	ll ans = 0;
	ll c = 0;

	for (int i = 0; i < n; i++){
		if (str[i] >= '0' && str[i] <= '9'){
			c = c * 10 + str[i] - '0';
		}
		else{
			ans += c;
			c = 0;
		}
	}

	ans += c;

	printf("%lld\n", ans);
}