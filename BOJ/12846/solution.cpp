#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {

	int n, a;
	scanf("%d", &n);

	stack < pair <int, int> > stk;

	ll ans = 0;

	stk.push(make_pair(0, 0));

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);

		if (stk.top().second < a) {
			stk.push(make_pair(i, a));
		}
		else {

			int le = -1;
			while (!stk.empty() && stk.top().second > a) {
				le = stk.top().first;
				ans = max(ans, (ll)(i - stk.top().first) * stk.top().second);
				stk.pop();
			}

			if (le == -1)le = i;

			if (stk.empty() || stk.top().second < a) {
				stk.push(make_pair(le, a));
			}
		}
	} // 5 4 3 2 3 4 

	while (!stk.empty()) {
		ans = max(ans, (ll)(n - stk.top().first + 1)*stk.top().second);
		stk.pop();
	}

	printf("%lld\n", ans);

}