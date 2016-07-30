#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

char str[203];
int conv['Z' + 3];

int main(){
	int n;
	scanf("%d", &n);

	scanf("%s", str);

	for (int i = 0; i < n; i++){
		scanf("%d", &conv['A' + i]);
	}

	int s = strlen(str);

	stack <double> val;
	stack <char> op;

	for (int i = 0; i < s; i++){
		char c = str[i];
		if (c == '+' || c == '-' || c == '*' || c == '/'){
			double a = val.top();
			val.pop();
			double b = val.top();
			val.pop();
			if (c == '+'){
				val.push(a + b);
			}
			else if (c == '-'){
				val.push(b - a);
			}
			else if (c == '*'){
				val.push(a * b);
			}
			else if (c == '/'){
				val.push(b / a);
			}
		}
		else{
			val.push(conv[c]);
		}
	}

	printf("%.2lf\n", val.top());
}