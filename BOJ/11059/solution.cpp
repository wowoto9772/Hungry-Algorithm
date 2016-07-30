#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[1003];
int s[1003];

int main() {

	scanf("%s", str + 1);

	int k = strlen(str + 1);

	for (int i = 1; i <= k; i++) {

		s[i] = s[i - 1] + str[i] - '0';

	}

	int ans = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = i + 1; j <= k; j += 2) {
			int m = (i + j) / 2;
			if (s[j] - s[m] == s[m] - s[i - 1]) {
				ans = max(ans, (j - i) + 1);
			}
		}
	}

	printf("%d\n", ans);
}