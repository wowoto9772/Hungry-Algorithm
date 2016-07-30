#include <stdio.h>
#include <stack>

using namespace std;

int x[1003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
	}

	stack <int> stk;

	int m = 1;
	for (int i = 1; i <= n; i++) {
		if (x[i] == m)m++;
		else {
			while (!stk.empty()) {
				if (stk.top() == m) {
					stk.pop();
					m++;
				}
				else {
					break;
				}
			}

			if (x[i] == m)m++;
			else {
				stk.push(x[i]);
			}
		}
	}

	while (!stk.empty()) {
		if (stk.top() == m) {
			stk.pop();
			m++;
		}
		else
			break;
	}

	if (stk.empty())printf("Nice\n");
	else {
		printf("Sad\n");
	}

}