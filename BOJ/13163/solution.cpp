#include <stdio.h>
#include <string.h>

char str[123];

int main(){

	int n;
	scanf("%d", &n);

	fgets(str, sizeof(str), stdin); // for buffer

	for(int i=1; i<=n; i++){
		
		fgets(str, sizeof(str), stdin);
		int s = strlen(str);
		
		if(str[s-1] == '\n'){
			str[s-1] = 0;
			s--;
		}

		bool god = false;

		for(int i=0; i<s; i++){
			if(str[i] == ' '){
				if(!god){
					god = true;
					printf("god");
				}else{
					continue;
				}
			}else{
				if(god)printf("%c", str[i]);
			}
		}

		printf("\n");

	}

}
