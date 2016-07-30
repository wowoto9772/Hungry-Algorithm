#include <stdio.h>

char str[16];
int d[13] = { 0, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s", str);

		int a = 0;
		for (int i = 0; i < 12; i++)a += str[i] - '0';
		if (a % 10 == str[12] - '0' && str[6] >= '1' && str[6] <= '4'){ // valid
			if (str[2] == '0' && str[3] == '2' && str[4] == '2' && str[5] == '9'){
				int y = 1900;
				if (str[6] >= '3'){ // 2000
					y += 100;
				}
				y += (str[0] - '0') * 10 + (str[1] - '0');
				if (y % 400 == 0)printf("YES\n");
				else if (y % 100 == 0)printf("NO\n");
				else if (y % 4 == 0)printf("YES\n");
				else{
					printf("NO\n");
				}
			}
			else{
				int m = (str[2] - '0') * 10 + (str[3] - '0');
				int d2 = (str[4] - '0') * 10 + str[5] - '0';
				if (m >= 1 && m <= 12){
					if (d[m] >= d2 && d2 >= 1)printf("YES\n");
					else
						printf("NO\n");
				}
				else{
					printf("NO\n");
				}
			}
		}
		else{
			printf("NO\n");
		}
	}
}

