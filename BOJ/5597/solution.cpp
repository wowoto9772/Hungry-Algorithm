#include <stdio.h>

bool chk[33];

int main() {

	for (int i = 1; i <= 28; i++) {
		
		int a;
		scanf("%d", &a);

		chk[a] = true;
	}

	for (int i = 1; i <= 30; i++)if (!chk[i])printf("%d\n", i);
}