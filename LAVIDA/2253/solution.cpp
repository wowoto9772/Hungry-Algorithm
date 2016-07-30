#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>

using namespace std;

char str[40003];

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

	int tc = 0;

	fgets(str, 10000, stdin); // for buffer

	while (t--) {

		fgets(str, 10000, stdin);

		int s = strlen(str);

		vector <int> op, val;

		int v = 0;
		bool flag = false;

		for (int i = 0; i < s; i++) {
			char c = str[i];
			if (c == ' ' || c == '\n') {
				if (flag)val.push_back(v);
				flag = false;
				v = 0;
			}
			else if (c == '+' || c == '-' || c == '*' || c == '/') {
				op.push_back(c);
			}
			else {
				// operand
				v = v * 10 + c - '0';
				flag = true;
			}
		}

		if (flag)val.push_back(v);

		vector <char> out;

		while (!op.empty()) {

			int pr = 0;

			for (int i = 0; i < op.size(); i++) {
				if (op[i] == '*' || op[i] == '/') {
					pr = 1;
					break;
				}
			}

			if (pr) {
				for (int i = 0; i < op.size(); i++) {
					if (op[i] == '*') {
						out.push_back(op[i]);
						val[i] *= val[i + 1];
						val[i + 1] = val[i];
						val[i] = op[i] = -1;
					}
					else if (op[i] == '/') {
						out.push_back(op[i]);
						val[i] /= val[i + 1];
						val[i + 1] = val[i];
						val[i] = op[i] = -1;
					}
				}
			}else{
				for (int i = 0; i < op.size(); i++) {
					if (op[i] == '+') {
						out.push_back(op[i]);
						val[i] += val[i + 1];
						val[i + 1] = val[i];
						val[i] = op[i] = -1;
					}
					else if (op[i] == '-') {
						out.push_back(op[i]);
						val[i] -= val[i + 1];
						val[i + 1] = val[i];
						val[i] = op[i] = -1;
					}
				}
			}

			for (int i = op.size() - 1; i >= 0; i--) {
				if (op[i] == -1)op.erase(op.begin() + i);
			}

			for (int i = val.size() - 1; i >= 0; i--) {
				if (val[i] == -1)val.erase(val.begin() + i);
			}
		}

		printf("Case #%d: ", ++tc);

		for (int i = 0; i < out.size(); i++)printf("%c ", out[i]);

		printf("%d\n", val[0]);

	}

}