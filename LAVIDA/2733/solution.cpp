#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	char str[12] = { 0 };
	for (int i = 0; i < n; i++)str[i] = (i + 1) + '0';

	while (next_permutation(str, str + n)) {
		int flg = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == (i + 1) + '0') {
				flg++;
				break;
			}
		}
		if (!flg)printf("%s\n", str);
	}

}

// perfect permutation | dearrangement permutation
