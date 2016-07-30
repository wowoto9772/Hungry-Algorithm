#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	int cnt[2] = { 0 };

	for (ll i = 2; i <= n; i <<= 1){
		cnt[0] += n / i;
	}

	for (ll i = 5; i <= n; i *= 5){
		cnt[1] += n / i;
	}

	for (ll i = 2; i <= m; i <<= 1){
		cnt[0] -= m / i;
	}
	for (ll i = 2; i <= n - m; i <<= 1){
		cnt[0] -= (n - m) / i;
	}
	for (ll i = 5; i <= m; i *= 5){
		cnt[1] -= m / i;
	}
	for (ll i = 5; i <= n - m; i *= 5){
		cnt[1] -= (n - m) / i;
	}

	printf("%d\n", min(cnt[0], cnt[1]));

	// n ! / m ! ( n - m ) !

}