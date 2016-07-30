#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

int x[10003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans += abs((ll)x[i] - x[j])*2;
		}
	}

	printf("%lld\n", ans);
}