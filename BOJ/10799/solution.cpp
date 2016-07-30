#include <stdio.h>
#include <string.h>

#include <stack>

using namespace std;

char str[100003];

int main() {

	scanf("%s", str);

	int s = strlen(str);

	stack <int> stk;

	int ans = 0;

	for (int i = 0; i < s; i++) {

		if (str[i] == '(' && str[i + 1] == ')') {
			ans += stk.size();
			i++;
		}
		else {
			if (str[i] == '(')stk.push(str[i]);
			else {
				ans++;
				stk.pop();
			}
		}

	}

	printf("%d\n", ans);


}