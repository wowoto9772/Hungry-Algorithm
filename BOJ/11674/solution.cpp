#include <stdio.h>

#include <string.h>

#define ll long long

char str[33];

int dr[] = {0, 0, 1, 1};
int dc[] = {0, 1, 0, 1};

int main(){

	scanf("%s", str);

	int s = strlen(str);

	printf("%d ", s);

	ll x = 0, y = 0;

	for(int i=0; i<s; i++){
		if(i)x <<= 1, y <<= 1;
		x += dr[str[i]-'0'];
		y += dc[str[i]-'0'];
	}

	printf("%lld %lld\n", y, x);

}
