#include <stdio.h>

#include <string.h>

char str[1003];

int b[1003];

int main(){

	while(true){

		fgets(str, sizeof(str), stdin);

		if(strcmp(str, "\n") == 0)break;

		int s = strlen(str);

		if(str[s-1] == '\n')s--;
		
		int n;
		scanf("%d", &n);

		for(int i=1; i<=n; i++){
			int x;
			scanf("%d", &x);

			b[x] = i-1;
		}

		for(int i=1; i<=n; i++){
			for(int j=b[i]; j<s; j+=n)printf("%c", str[j]);
		}

		printf("\n");

		fgets(str, sizeof(str), stdin); // for buffer

	}

}
