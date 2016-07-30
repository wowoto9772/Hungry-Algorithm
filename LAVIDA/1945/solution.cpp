#include <stdio.h>
#include <string.h>

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		char str[30] = { 0 };
		while (!strcmp(str, ""))gets(str);
		int s = strlen(str);

		int b = 0, g = 0;
		for (int i = 0; i < s; i++){
			if (str[i] == 'b' || str[i] == 'B')b++;
			else if (str[i] == 'g' || str[i] == 'G')g++;
		}

		printf("%s is ", str);
		if (b > g)printf("A BADDY");
		else if (b < g)printf("GOOD");
		else
			printf("NEUTRAL");
		printf("\n");
	}
}