#include <stdio.h>

#include <string.h>

char str[103][103];

int main(){

	int r, c;
	scanf("%d %d", &r, &c);

	for(int i=0; i<r; i++)scanf("%s", str[i]);

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			str[i][2*c-1-j] = str[i][j];
			str[2*r-1-i][j] = str[i][j];
			str[2*r-1-i][2*c-1-j] = str[2*r-1-i][j];
		}
	}

	int a, b;
	scanf("%d %d", &a, &b);

	a--, b--;

	if(str[a][b] == '#')str[a][b] = '.';
	else
		str[a][b] = '#';

	for(int i=0; i<2*r; i++)printf("%s\n", str[i]);

}
