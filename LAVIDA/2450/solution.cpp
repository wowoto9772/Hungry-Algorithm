#include <stdio.h>
#include <string.h>

char ptn[100003], tar[100003];

int main(){

	while (scanf("%s %s", ptn, tar) == 2){

		int p = strlen(ptn);
		int t = strlen(tar);

		int l = 0;

		for (int i = 0; i < t; i++){
			if (tar[i] == ptn[l]){
				l++;
				if (l == p)break;
			}
		}

		printf("%s\n", (l == p) ? "Yes" : "No");

	}

}