#include <stdio.h>
#include <string.h>

char str[33];
int lev[33];

int main(){
	scanf("%s", str);

	int s = strlen(str);

	int stk[33] = { 0 };
	int top = 0;

	int ans = 0;
	int ans2 = 0;
	for (int i = 0; i < s; i++){
		if (str[i] == '(')stk[top++] = 2;
		else if (str[i] == '[')stk[top++] = 3;
		else if (str[i] == ')'){
			if (top == 0 || stk[top - 1] == 3){
				ans = 0;
				break;
			}
			else{
				top--;
				if (lev[top + 1]){
					lev[top] += 2 * lev[top + 1];
					lev[top + 1] = 0;
				}else
					lev[top] += 2;
			}
		}
		else if (str[i] == ']'){
			if (top == 0 || stk[top - 1] == 2){
				ans = 0;
				break;
			}
			else{
				top--;
				if (lev[top + 1]){
					lev[top] += 3 * lev[top + 1];
					lev[top + 1] = 0;
				}
				else
					lev[top] += 3;
			}
		}
	}

	printf("%d\n", lev[0]);
}