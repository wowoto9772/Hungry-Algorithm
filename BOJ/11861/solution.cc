#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

using ll = long long;

class ele {
public:
	ll v, p;
	ele() {}
	ele(ll a, ll b) { v = a, p = b; }
};

int main() {

	int n;
	scanf("%d", &n);

	ll ans = 0;

	stack <ele> stk;
	stk.emplace(0, -1);

	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);

		if (stk.top().v == a)continue;

		ele lst = { a, i };
		while (stk.top().v > a) {
			ans = max(ans, (i - stk.top().p) * stk.top().v);
			lst = stk.top();
			stk.pop();
		}

		lst.v = a;
		stk.emplace(lst);
	}

	if (!stk.empty()) {
		ll l = n;
		while (!stk.empty()) {
			ele c = stk.top();
			ans = max(ans, (l - c.p + 1)*c.v);
			stk.pop();
		}
	}

	printf("%lld\n", ans);

}

/*
 * 5 
 * 3 3 2 2 2
 */
