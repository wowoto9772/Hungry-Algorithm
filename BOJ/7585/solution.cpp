#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

char str[5000 + 3];

int par['z' + 3];

int main() {

	par['('] = ')';
	par['{'] = '}';
	par['['] = ']';

	while (fgets(str, 4000, stdin)) {
		
		int s = strlen(str);
		
		if (str[0] == '#')break;

		s--; // last character : '\n'

		stack <char> stk;

		bool flag = false;

		for (int i = 0; !flag && i < s; i++) {
			if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
				stk.push(str[i]);
			}
			else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
				if (stk.empty())flag = true;
				else {
					if (par[stk.top()] == str[i]) {
						stk.pop();
					}
					else {
						flag = true;
					}
				}
			}
		}	

		if (!stk.empty())flag = true;

		printf("%s\n", !flag ? "Legal" : "Illegal");

	}

}