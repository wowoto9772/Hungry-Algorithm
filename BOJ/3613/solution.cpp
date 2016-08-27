#include <stdio.h>
#include <string.h>

char str[103];

int main(){

	scanf("%s", str);

	int s = strlen(str);

	bool java = false, cpp = false, err = false;

	for(int i=0; i<s; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			if(i)java = true;
			else{
				err = true;
			}
		}
		else if(str[i] == '_'){
			if(i == 0 || i == s-1 || str[i+1] == '_')err = true;
			else{
				cpp = true;
			}
		}
	}

	if(java && cpp)err = true;

	if(err)printf("Error!");
	else{
		if(java){
			// to cpp
			for(int i=0; i<s; i++){
				if(str[i] >= 'A' && str[i] <= 'Z'){
					printf("_%c", str[i] + ('a' - 'A'));
				}else{
					printf("%c", str[i]);
				}
			}
		}else{
			// to java
			bool und = false;
			for(int i=0; i<s; i++){
				if(str[i] == '_')und = true;
				else{
					if(und){
						und = false;
						printf("%c", str[i] - ('a' - 'A'));
					}else{
						printf("%c", str[i]);
					}
				}
			}
		}
	}

}
