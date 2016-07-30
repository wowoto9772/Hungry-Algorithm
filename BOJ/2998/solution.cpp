#include <stdio.h>
#include <string.h>

char str[103];

int main() {

	scanf("%s", str);

	int s = strlen(str);

	int ans[103];

	int top = 0;

	for (int i = s - 1; i >= 0; i-=3) {
		int k = 1;
		int d = 0;
		for (int j = i; j >= i - 2 && j >= 0; j--) {
			d += (str[j] == '1') * k;
			k <<= 1;
		}
		ans[top++] = d;
	}

	for (int i = top - 1; i >= 0; i--)printf("%d", ans[i]);

}