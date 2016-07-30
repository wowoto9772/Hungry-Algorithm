#include <stdio.h>
#include <string.h>

char str[103], ptn[103];

int main(){

	int n;
	scanf("%d", &n);

	scanf("%s", ptn);

	int p = strlen(ptn);

	for (int i = 1; i <= n; i++){

		scanf("%s", str);

		int s = strlen(str);

		int l = 0, r = s - 1;
		int l_ = 0, r_ = p - 1;

		bool flag = false;

		while (l_ <= r_ && l <= r){
			int c = 0;
			if (ptn[l_] == str[l])l_++, l++;
			else
				c++;
			if (ptn[r_] == str[r])r_--, r--;
			else
				c++;

			if (c == 2)break;
		}

		if (ptn[l_] == '*' && ptn[r_] == '*')printf("DA\n");
		else
			printf("NE\n");

	}

}