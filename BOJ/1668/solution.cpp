#include <stdio.h>
#include <stack>
#include <algorithm>

using namespace std;

int e[53];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%d", &e[i]);

	int ans = 0;

	stack <int> stk;

	for (int i = 0; i < n; i++) {
		if (stk.empty())stk.push(e[i]);
		else {
			if (stk.top() < e[i])stk.push(e[i]);
		}
	}


	printf("%d\n", stk.size());

	while (!stk.empty())stk.pop();

	ans = 0;

	reverse(e, e + n);

	for (int i = 0; i < n; i++) {
		if (stk.empty())stk.push(e[i]);
		else {
			if (stk.top() < e[i])stk.push(e[i]);
		}
	}

	printf("%d\n", stk.size());

}