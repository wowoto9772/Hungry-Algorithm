#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define ll long long

ll sum['Z' + 3];

char str[13];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%s", str);

		int s = strlen(str);

		ll r = 1;

		for (int j = s - 1; j >= 0; j--) {
			sum[str[j]] += r;
			r *= 10LL;
		}

	}

	priority_queue < pair <int, int> > q;

	for (int i = 'A'; i <= 'Z'; i++) {
		if (sum[i])q.emplace(sum[i], i);
	}

	ll ans = 0;
	int g = 9;
	while (!q.empty()) {
		ans += q.top().first * g--;
		q.pop();
	}

	printf("%lld\n", ans);

}