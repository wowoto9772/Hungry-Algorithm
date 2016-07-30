#include <stdio.h>
#include <string.h>

#include <algorithm>

using namespace std;

char A[53], B[53];

int main() {
	
	scanf("%s %s", A, B);

	int a = strlen(A), b = strlen(B);

	int ans = b;

	for (int i = 0; i <= b-a; i++) {

		int l = 0, r = i;

		int cmp = 0;

		while (r < b && l < a) {
			if (A[l] != B[r])cmp++;
			l++, r++;
		}

		ans = min(ans, cmp);
	}

	printf("%d\n", ans);

}