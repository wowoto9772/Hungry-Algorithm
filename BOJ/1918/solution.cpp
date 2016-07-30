#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

char str[303];

int prior(char op){
	if (op == '(' || op == ')')return 0;
	else if (op == '+' || op == '-')return 1;
	else if (op == '*' || op == '/')return 2;
	else
		return -1;
}

int main(){

	scanf("%s", str);

	int s = strlen(str);
	stack <char> stk;

	for (int i = 0; i < s; i++){
		char c = str[i];
		if (c == '+' || c == '-' || c == '*' || c == '/'){
			while (!stk.empty() && prior(stk.top()) >= prior(c)){
				printf("%c", stk.top());
				stk.pop();
			}
			stk.push(c);
		}
		else if (c == '('){
			stk.push(c);
		}
		else if (c == ')'){
			while (stk.top() != '('){
				printf("%c", stk.top());
				stk.pop();
			}
			stk.pop();
		}
		else{ // operand
			printf("%c", c);
		}
	}

	while (!stk.empty()){
		printf("%c", stk.top());
		stk.pop();
	}

}