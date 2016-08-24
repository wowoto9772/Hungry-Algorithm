#include <stdio.h>

#include <string.h>

char str[100003];

int main(){

	scanf("%s", str);

	int s = strlen(str);

	int x = 0;
	for(int i=0; i<s; i++)if(str[i] == 'a')x++;

	if(x == s){
		for(int j=1; j<s; j++)printf("a");
		printf("z");
	}else{

		for(int i=0; i<s; i++){
			if(str[i] == 'a'){
				printf("%c", str[i]);
				continue;
			}
			else{
				for(int j=i; j<s; j++){
					if(str[j] != 'a'){
						printf("%c", str[j]-1);
					}else{
						for(int k=j; k<s; k++)printf("%c", str[k]);
						break;
					}
				}
				break;
			}
		}

		printf("\n");

	}

}
