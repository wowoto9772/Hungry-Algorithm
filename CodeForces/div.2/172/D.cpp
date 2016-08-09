#include <stdio.h>
#include <algorithm>

using namespace std;

int stk[100003];

int main() {

	int n;
	scanf("%d", &n);

	int top = 0;

	int ans = 0;

	for (int i = 0; i < n; i++) {

		int e;
		scanf("%d", &e);

		while (top && e > stk[top - 1]) { // interval l~r (max 2 xor)
			if (ans < (e^stk[top - 1]))ans = max(ans, e^stk[top - 1]);
			top--;
		} // same two xor :: 0

		if (top)ans = max(ans, e^stk[top - 1]);

		stk[top++] = e;

	}

	printf("%d\n", ans);

}
