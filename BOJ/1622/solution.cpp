#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char a[1003], b[1003];

int main() {

	while (fgets(a, sizeof(a), stdin) && fgets(b, sizeof(b), stdin)) {

		int s = strlen(a), e = strlen(b);

		if(a[s-1] == '\n')s--;
		if(b[e-1] == '\n')e--;

		sort(a, a + s);
		sort(b, b + e);

		int l = 0, r = 0;

		while (l < s && r < e) {
			if (a[l] == b[r]) {
				printf("%c", a[l]);
				l++, r++;
			}
			else if (a[l] > b[r])r++;
			else
				l++;
		}

		printf("\n");

	}

}
