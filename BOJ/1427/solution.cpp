#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[13];

int main() {

	scanf("%s", str);

	int s = strlen(str);

	sort(str, str + s);
	reverse(str, str + s);

	printf("%s\n", str);

}