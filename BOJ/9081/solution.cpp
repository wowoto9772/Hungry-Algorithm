#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[103];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%s", str);

		int s = strlen(str);

		if (!next_permutation(str, str + s)) {
			prev_permutation(str, str + s);
		}

		printf("%s\n", str);

	}

}
