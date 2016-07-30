#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[13];

int main() {

	int n;

	while (scanf("%s %d", str, &n) == 2) {

		printf("%s %d = ", str, n);

		n--;

		int s = strlen(str);
		
		while (n-- && next_permutation(str, str + s));

		if (n == -1)printf("%s\n", str);
		else
			printf("No permutation\n");

	}

}