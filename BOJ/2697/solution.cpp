#include <stdio.h>
#include <string.h>

#include <algorithm>

using namespace std;

char str[83];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%s", str);

		int s = strlen(str);

		if (!next_permutation(str, str + s)) {
			printf("BIGGEST\n");
		}
		else {
			printf("%s\n", str);
		}

	}

}