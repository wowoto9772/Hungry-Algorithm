#include <stdio.h>
#include <string.h>

char str[10003];
char cmp[] = "OI";

int main(){
	scanf("%s", str);

	int s = strlen(str);

	int J = 0, I = 0, f = 0;

	for (int i = 0; i < s; i++){
		if (str[i] == cmp[f]){
			f++;
			if (f == 2){
				if (i >= 2){
					if (str[i - 2] == 'J')J++;
					else if (str[i - 2] == 'I')I++;
				}
				f = 0;
			}
		}
		else{
			f = 0;
		}
	}

	printf("%d\n%d\n", J, I);
}