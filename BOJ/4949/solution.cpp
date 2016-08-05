#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

char str[103];

int main() {

	while (true) {

		fgets(str, sizeof(str), stdin);

		if (!strcmp(str, ".\n") || !strcmp(str, "."))break;

		int s = strlen(str);

		stack <char> stk;

		bool god = true;

		for (int i = 0; god && i < s; i++) {
			if (str[i] == '(' || str[i] == '[')stk.push(str[i]);
			else {
				if (str[i] == ')') {
					if (stk.empty())god = false;
					else {
						if (stk.top() == '(')stk.pop();
						else
							god = false;
					}
				}
				else if (str[i] == ']') {
					if (stk.empty())god = false;
					else {
						if (stk.top() == '[')stk.pop();
						else
							god = false;
					}
				}
			}
		}

		if (!stk.empty())god = false;

		printf("%s\n", god ? "yes" : "no");
	}

}