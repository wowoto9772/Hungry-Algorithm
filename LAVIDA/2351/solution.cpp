#include <string.h>
#include <stdio.h>

long long par(char str[]){
	long long ret = 0;
	int s = strlen(str);
	
	int a = s - 9;
	if (a < 0)a = 0;

	for (int i = a; i < s; i++)ret = ret * 10 + str[i] - '0';

	return ret;
}

int main()
{
	int n;
	scanf("%d", &n);

	long long x = 1;

	for (int i = 1; i <= n; i++){
		char str[106] = { 0 };
		scanf("%s", str);

		long long k = par(str);
		x *= k;
		x %= 1000000000;
	}

	printf("%lld\n", x);
}