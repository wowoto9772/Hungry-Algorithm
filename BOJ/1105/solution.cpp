#include <stdio.h>
#include <string.h>

char L[13], R[13];

int main() {

	scanf("%s %s", L, R);

	int l = strlen(L), r = strlen(R);

	if (l != r)printf("0\n");
	else {

		int ans = 0;

		for (int i = 0; i < l; i++) {

			if (L[i] == R[i])ans += L[i] == '8';
			else {
				break;
			}

		}

		printf("%d\n", ans);

	}

}