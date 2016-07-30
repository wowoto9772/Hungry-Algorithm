#include <stdio.h>
#include <functional>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	if (!n)printf("0\n");
	else {

		priority_queue <ll, vector<ll>, greater<ll>> mq;

		for (int i = 1; i <= 9; i++)mq.push(i);

		while (n-- && !mq.empty()) {

			ll f = mq.top(); mq.pop();

			if (n == 0) {
				printf("%lld\n", f);
				return 0;
			}

			for (int i = f % 10 - 1; i >= 0; i--) {
				mq.push((ll)f * 10LL + i);
			}

		}

		printf("-1\n");

	}
} // max 9876543210 (1022)