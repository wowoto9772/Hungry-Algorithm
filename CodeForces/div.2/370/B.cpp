#include <stdio.h>

#include <string.h>

#include <vector>

#include <algorithm>

using namespace std;

char str[100003];

int main(){

	scanf("%s", str);

	int s = strlen(str);

	if(s&1)printf("-1");
	else{

		int L = 0, R = 0, D = 0, U = 0;

		int lr = 0, du = 0;

		for(int i=0; i<s; i++){
			if(str[i] == 'L')L++;
			else if(str[i] == 'R')R++;
			else if(str[i] == 'D')D++;
			else
				U++;
		}

		lr = L+R;
		du = D+U;

		int add = 0;

		if(lr&1){
			lr--;
			du++;
			add++;
			if(D > U)U++;
			else
				D++;

			if(L > R)L--;
			else
				R--;
		}

		lr>>=1;
		du>>=1;

		printf("%d", abs(lr-L) + abs(du-D) + add);

	}

}
