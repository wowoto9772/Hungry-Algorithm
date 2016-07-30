#include <stdio.h>
#include <stack>
#define ll long long

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	stack <int> stk;

	for (int i = 1; i <= n; i++) {
		int v;
		scanf("%d", &v);
		if (!v)stk.pop();
		else
			stk.push(v);
	}

	ll ans = 0;
	while (!stk.empty()) {
		ans += stk.top(); stk.pop();
	}

	printf("%lld\n", ans);

}