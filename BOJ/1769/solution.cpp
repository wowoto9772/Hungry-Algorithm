#include <stdio.h>
#include <string.h>

char str[1000003];

int main(){
	scanf("%s", str);

	int s = strlen(str);
	int g = 0;
	for (int i = 0; i < s; i++){
		g += str[i] - '0';
	}
	int c;
	if (s > 1)c = 1;
	else
		c = 0;

	while (g >= 10){
		int ng = 0;
		while (g){
			ng += g % 10;
			g /= 10;
		}
		g = ng;
		c++;
	}

	printf("%d\n%s\n", c, g%3 ? "NO" : "YES");

}