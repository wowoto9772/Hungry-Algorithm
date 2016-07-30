#include <stdio.h>
#include <string.h>

char str[100003];
int c[10];

int main(){
	scanf("%s", str);

	int s = strlen(str);
	int m = 0;

	for (int i = 0; i < s; i++){
		int k = str[i] - '0';
		c[k]++;
		m += k;
		m %= 3;
	}

	if (m)printf("-1\n");
	else{
		if (!c[0])printf("-1\n");
		else{
			for (int i = 9; i >= 0; i--){
				while (c[i]){
					printf("%d", i);
					c[i]--;
				}
			}
			printf("\n");
		}
	}
}