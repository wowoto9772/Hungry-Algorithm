#include <stdio.h>
#include <math.h>
#include <string.h>

// 10 * log(10.0) / log(2.0)
// = 33

char str[36];
int main(){
	int d;
	scanf("%s %d", str, &d);

	int s = strlen(str);
	int ans = 0;
	int g = 1;

	for (int i = s - 1; i >= 0; i--){
		if (str[i] < 'A')ans += g * (str[i] - '0');
		else
			ans += g * (str[i] - 'A' + 10);
		g *= d;
	}

	printf("%d\n", ans);
}