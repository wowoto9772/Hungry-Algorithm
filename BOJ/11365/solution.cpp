#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

char str[1003];

int main() {
	
	while (true) {

		fgets(str, 1000, stdin);

		if (!strcmp(str, "END\n"))break;

		int s = strlen(str);
		str[--s] = 0;

		reverse(str, str + s);

		printf("%s\n", str);


	}

}