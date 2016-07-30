#include <stdio.h>

char str[13][13];
char dstr[13][26];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)scanf("%s", str[i]);
	for (int i = 0; i < n; i++)scanf("%s", dstr[i]);

	bool flag = false;
	
	for (int k = 0; k < n && !flag; k++){
		for (int i = 0; i < 2 * m && !flag; i++){
			if (dstr[k][i] != str[k][i / 2])flag = true;
		}
	}

	if (flag)printf("Not Eyfa\n");
	else
		printf("Eyfa\n");
}