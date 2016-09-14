#include <stdio.h>

#include <string.h>

int pars(char *str){

	int s = strlen(str);

	int h = 0, m = 0;

	int i;

	int v = 0;

	for(i=0; i<s; i++){
		if(str[i] == ':' || str[i] == '.'){
			h = v;
			v = 0;
			i++;
			break;
		}else{
			v = v * 10 + str[i] - '0';
		}
	}

	for(;i<s;i++){
		v = v * 10 + str[i] - '0';
	}

	m = v;

	return (h * 60 + m);

}

char str[10];

int main(){

	while(true){

		int sub = 0, add = 0;

		while(scanf("%s", str) == 1){

			if(!strcmp(str, "###") || !strcmp(str, "$$$"))break;

			if(str[0] == '+'){
				add += pars(str+1);
			}else{
				sub += pars(str+1);
			}

		}

		int cur = add - sub;

		printf("%d:%02d\n", cur/60, cur%60);

		if(!strcmp(str, "###"))break;

	}

}
