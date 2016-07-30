#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
	int n;
	scanf("%d", &n);

	ll ans = INT_MIN, cur = 0;

	for (int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);
		cur += a;
		if (ans < cur)ans = cur;
		if (cur < 0)cur = 0;
	}

	printf("%lld\n", ans);
}