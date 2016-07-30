#include <stdio.h>

char str[33];
int c['z' + 3];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%s", str);
		c[str[0]]++;
	}

	int g = 0;
	for (int i = 'a'; i <= 'z'; i++){
		if (c[i] >= 5)printf("%c", i), g++;
	}

	if (!g)printf("PREDAJA");
}