#include <stdio.h>
#include <string.h>

#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int prior(char op) {

	if (op == '(' || op == ')')return 0;
	else if (op == '+' || op == '-')return 1;
	else if (op == '*' || op == '/')return 2;
	else
		return -1;

}

int main() {

	int t;
	scanf("%d", &t);

	char str[3003] = { 0 };
	fgets(str, 600, stdin); // for buffer

	while (t--) {

		for (int i = 0; i < 3000; i++)str[i] = 0;
		fgets(str, 600, stdin); // input's last character is '\n'

		int s = strlen(str);

		//stack <int> val;
		stack <char> op;

		vector <string> ans;

		for (int i = 0; i < s; i++)if (str[i] == '\n')str[i] = ' ';

		for (int i = 0; i < s; i++) {

			char c = str[i];

			if (c != ' ') {

				string tmp;

				for (int j = i; j < s; j++) {

					if (str[j] == ' ') {
						i = j;
						break;
					}
					else {
						tmp += str[j];
						if (j == s - 1)i = j + 1;
					}
				}

				if ('0' <= tmp[0] && tmp[0] <= '9'
					|| tmp.size() >= 2 && tmp[0] == '-') {
					// operand
					ans.push_back(tmp);
				}
				else {
					// operator
					c = tmp[0];
					if (c == '(') {
						op.push('(');
					}
					else if (c == ')') {
						while (op.top() != '(') {
							char m_ = op.top();
							string m;
							m += m_;
							ans.push_back(m);
							op.pop();
						}
						op.pop();
					}
					else {
						while (!op.empty() && prior(op.top()) >= prior(c)) {
							char m_ = op.top();
							string m;
							m += m_;
							ans.push_back(m);
							op.pop();
						}
						op.push(c);
					}
				}
			}
		}

		while (!op.empty()) {
			char m_ = op.top();
			string m;
			m += m_;
			ans.push_back(m);
			op.pop();
		}

		for (int i = 0; i < ans.size(); i++) {
			if (i)printf(" ");
			if(ans[i].size())printf("%s", ans[i].c_str());
		}

		printf("\n");
	}
}