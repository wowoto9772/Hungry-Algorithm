#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

char str[100003];

int main(){

	int n;
	scanf("%d", &n);

	int c = 0;

	while (n--){
		
		scanf("%s", str);

		int s = strlen(str);

		stack <int> stk;

		for (int i = 0; i < s; i++){
			if (stk.empty()){
				stk.push(str[i]);
			}
			else{
				if (stk.top() != str[i]){
					stk.push(str[i]);
				}
				else{
					stk.pop();
				}
			}
		}

		if (stk.empty()){
			c++;
		}

	}

	printf("%d\n", c);
}