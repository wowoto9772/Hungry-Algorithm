#include <stdio.h>

int A(int a){
	return a < -a ? -a : a;
}

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		char str[11] = { 0 };
		scanf("%s", str);

		int l = 26 * 26 * (str[0] - 'A') + 26 * (str[1] - 'A') + str[2] - 'A';
		int r = (str[4] - '0') * 1000 + (str[5] - '0') * 100 + (str[6] - '0') * 10 + str[7] - '0';

		printf("%s\n", A(l - r) <= 100 ? "nice" : "not nice");
	}
}