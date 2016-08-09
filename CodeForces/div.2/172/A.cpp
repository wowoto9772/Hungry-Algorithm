#include <stdio.h>

#include <string.h>

char str[1003];

int main() {

	scanf("%s", str);

	if (str[0] >= 'a')str[0] -= 'a' - 'A';

	printf("%s\n", str);

}