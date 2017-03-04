#include <stdio.h>
#include <string.h>

char str[333338];

void PRINT(int a){
	if (!a)printf("000");
	else if (a == 1)printf("001");
	else if (a == 2)printf("010");
	else if (a == 3)printf("011");
	else if (a == 4)printf("100");
	else if (a == 5)printf("101");
	else if (a == 6)printf("110");
	else if (a == 7)printf("111");
}

int main(){
	scanf("%s", str);

	int s = strlen(str);

	int g = str[0] - '0';
	if (g < 4){
		if (g == 1)printf("1");
        else if (g == 2)printf("10");
		else if (g == 3)printf("11");
        else
            printf("0");
	}
	else{
		PRINT(g);
	}
	for (int i = 1; i<s; i++){
		g = str[i] - '0';
		PRINT(g);
	}printf("\n");
}
