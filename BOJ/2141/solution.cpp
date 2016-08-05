#include <stdio.h>

#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {

	int n;
	scanf("%d", &n);

	vector < pair <ll, ll> > sexy(n + 1);

	ll tcnt = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &sexy[i].first, &sexy[i].second);
		tcnt += sexy[i].second;
	}

	sexy[0] = sexy[1];
	sort(sexy.begin() + 1, sexy.end());

	ll center = (tcnt >> 1) + (tcnt & 1);
	ll cur = 0;

	for (int i = 1; i <= n; i++) {

		if (cur + sexy[i].second < center) {
			cur += sexy[i].second;
		}
		else {
			printf("%d\n", sexy[i].first);
			break;
		}

	}

}