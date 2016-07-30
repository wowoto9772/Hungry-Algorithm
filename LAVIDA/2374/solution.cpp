#include <stdio.h>
#include <string.h>

char str[100005];

void swp(char *a, char *b){
	char t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	//freopen("large_dat4.in", "r", stdin);
	//freopen("large_dat4.out", "w", stdout);
	//freopen("large_GGdat3.in", "r", stdin);
	//freopen("large_GGdat3.out", "w", stdout);

	while (scanf("%s", str) == 1){

		int s = strlen(str);

		int c = 0;

		for (int i = 0; i < s; i++){
			int a = str[i] - '0';
			if (!(a % 2))c++;
		}


		if (!c)printf("-1\n");
		else{
			int x = -1;
			int e = str[s - 1] - '0';
			for (int i = 0; i < s - 1; i++){
				int b = str[i] - '0';
				if (!(b % 2)){
					x = i;
					if (b < e){
						break;
					}
				}
			}

			swp(&str[x], &str[s - 1]);

			printf("%s\n", str);
		}
	}
}