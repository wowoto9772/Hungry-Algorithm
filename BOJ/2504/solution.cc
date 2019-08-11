#include <cstdio>
#include <cstring>

using namespace std;

char str[33];
int lev[33];

int main(){
	scanf("%s", str);

	int s = strlen(str);

	int stk[33] = { 0 };
	int top = 0;

    bool flag = false;
	int ans = 0;

	for (int i = 0; i < s && !flag; i++){
		if (str[i] == '(')stk[top++] = 2;
		else if (str[i] == '[')stk[top++] = 3;
		else if (str[i] == ')'){
			if (top == 0 || stk[top - 1] == 3){
				flag = true;
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
				flag = true;
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

    if(flag)printf("0");
	else
        printf("%d\n", lev[0]);
}