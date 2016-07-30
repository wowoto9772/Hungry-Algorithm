#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char *func(char a[]){
	sort(a, a + 4);
	int M = (a[3] - '0') * 1000 + (a[2] - '0') * 100 + (a[1] - '0') * 10 + (a[0] - '0');
	int m = (a[0] - '0') * 1000 + (a[1] - '0') * 100 + (a[2] - '0') * 10 + (a[3] - '0');
	int cmp = M - m;
	a[0] = cmp / 1000 + '0';
	cmp %= 1000;
	a[1] = cmp / 100 + '0';
	cmp %= 100;
	a[2] = cmp / 10 + '0';
	cmp %= 10;
	a[3] = cmp + '0';
	return a;
}

char n[6];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s", n);

		int c = 0;
		while (strcmp(n, "6174")){
			c++;
			strcpy(n, func(n));
		}

		printf("%d\n", c);
	}
}