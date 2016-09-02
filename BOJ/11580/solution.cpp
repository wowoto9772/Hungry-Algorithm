#include <stdio.h>

char str[1003];

bool chk[2003][2003];

int main(){

	int x = 1000, y = 1000;

	chk[x][y] = true;

	int n;
	scanf("%d", &n);

	scanf("%s", str);

	for(int i=0; i<n; i++){

		if(str[i] == 'N')y++;
		else if(str[i] == 'S')y--;
		else if(str[i] == 'E')x++;
		else{
			x--;
		}

		chk[x][y] = true;

	}

	int ans = 0;

	for(int i=0; i<=2000; i++)for(int j=0; j<=2000; j++)ans += chk[i][j];

	printf("%d\n", ans);

}
