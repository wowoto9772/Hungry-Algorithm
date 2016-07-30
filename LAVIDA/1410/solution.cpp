#include <stdio.h>
#include <string.h>

int a, b;
char cmp[5];

int main(){
	int tc = 0;
	while (scanf("%d %s %d", &a, cmp, &b) == 3){
		if (cmp[0] == 'E')break;

		bool ans = false;
		if (!strcmp(cmp, "<")){
			if (a < b)ans = true;
		}
		else if (!strcmp(cmp, "<=")){
			if (a <= b)ans = true;
		}
		else if (!strcmp(cmp, ">")){
			if (a > b)ans = true;
		}
		else if (!strcmp(cmp, ">=")){
			if (a >= b)ans = true;
		}
		else if (!strcmp(cmp, "==")){
			if (a == b)ans = true;
		}
		else if (!strcmp(cmp, "!=")){
			if (a != b)ans = true;
		}

		printf("Case %d: %s\n", ++tc, ans ? "true" : "false");
	}
}