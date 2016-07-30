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

	char str[10003] = { 0 };
	//	fgets(str, 600, stdin); // for buffer

	while (true) {

		fgets(str, 8000, stdin); // input's last character is '\n'

		if (!strcmp(str, "end\n"))break;

		int s = strlen(str); // last character is '\n'
		s--;

		//stack <int> val;
		stack <char> op;

		vector <string> ans;

		bool operand = false;

		bool error = false;

		for (int i = 0; i < s; i++) {

			char c = str[i];

			if (c != ' ') {

				string tmp;

				if ('0' <= str[i] && str[i] <= '9') {

					for (int j = i; j < s; j++) {
						if ('0' <= str[j] && str[j] <= '9') {
							tmp += str[j];
							if (j == s - 1)i = j + 1;
						}
						else {
							i = j - 1;
							break;
						}
					}

				}
				else {
					tmp += str[i];
				}

				if ('0' <= tmp[0] && tmp[0] <= '9') {
					// operand
					if (!operand) {

						ans.push_back(tmp);
						operand = true;

					}
					else {
						error = true;
						break;
					}
				}
				else {
					// operator
					c = tmp[0];
					if (c == '(') {
						op.push('(');
					}
					else if (c == ')') {

						while (true) {

							if (op.empty()) {
								error = true;
								break;
							}

							if (op.top() != '(') {
								char m_ = op.top();
								string m;
								m += m_;
								ans.push_back(m);
								op.pop();
							}
							else
								break;

						}

						if (!error)op.pop();
						else
							break;
					}
					else {

						if (c == '*' || c == '/' || c == '+' || c == '-') {

							if (operand) {

								while (!op.empty() && prior(op.top()) >= prior(c)) {

									if (op.top() == '(') {
										error = true;
										break;
									}

									char m_ = op.top();
									string m;
									m += m_;
									ans.push_back(m);
									op.pop();
								}

								operand = false;
								op.push(c);

							}
							else {

								error = true;
								break;

							}
						}
						else {
							error = true;
							break;
						}
					}
				}
			}
		}

		while (!op.empty()) {
			char m_ = op.top();

			if (op.top() == '(') {
				error = true;
				break;
			}

			string m;
			m += m_;
			ans.push_back(m);
			op.pop();
		}

		if (error || !operand)printf("syntax error");
		else {

			for (int i = 0; i < ans.size(); i++) {
				if (i)printf(" ");
				if (ans[i].size())printf("%s", ans[i].c_str());
			}

		}

		printf("\n");
	}
}