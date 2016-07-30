#include <stdio.h>
#include <string.h>

const char simon[] = "Simon says";

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		char str[105] = { 0 };
		while (!strcmp(str, ""))gets(str);
		int s = strlen(str);
		int g = 0;

		for (int i = 0; i < s && g < 10; i++){
			if (str[i] == simon[i])g++;
			else{
				break;
			}
		}

		if (g == 10)printf("%s\n", str + 10);
	}
}