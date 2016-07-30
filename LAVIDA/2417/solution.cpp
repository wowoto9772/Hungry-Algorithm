#include <stdio.h>
#include <string.h>

char str[230];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s", str);

		if (!strcmp(str, "0")){
			printf("0\n");
			continue;
		}
		else if (!strcmp(str, "1")){
			printf("0.5\n");
			continue;
		}

		int s = strlen(str);

		int c[230] = { 0 };
		int a[230] = { 0 };

		for (int i = 0; i < s; i++){
			c[i] += str[i] - '0';
			if (c[i] % 2){
				a[i] = c[i] / 2;
				c[i + 1] += 10;
			}
			else{
				a[i] = c[i] / 2;
			}
		}

		for (int i = 0; i < s; i++){
			if (a[i]){
				for (int j = i; j < s; j++)printf("%d", a[j]);
				if ((str[s - 1] - '0') % 2)printf(".5");
				printf("\n");
				break;
			}
		}
	}
}