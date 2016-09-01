#include <stdio.h>
#include <string.h>

char str[26];

int main(){
	while(scanf("%s", str) == 1){
		if(strcmp(str, "0+0=0") == 0){
			printf("True\n");
			return 0;
		}

		int s = strlen(str);

		int b = 0, c = 0, d = 0;

		int st = 0;

		for(int i=0; i<s; i++){
			if(str[i] == '+'){
				for(int j=i-1; j>=st; j--){
					b = b * 10 + str[j] - '0';
				}
				st = i+1;
			}
			else if(str[i] == '='){                
				for(int j=i-1; j>=st; j--){
					c = c * 10 + str[j] - '0';
				}
				st = i+1;
			}
			else if(i == s-1){
				for(int j=i; j>=st; j--){
					d = d * 10 + str[j] - '0';
				}
			}
		}
		if(b+c == d)printf("True\n");
		else
			printf("False\n");
	}
}
