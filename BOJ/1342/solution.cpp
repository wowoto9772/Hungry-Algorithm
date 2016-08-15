#include <stdio.h>
#include <string.h>

#include <algorithm>

using namespace std;

char str[13];

int main() {

	scanf("%s", str);

	int s = strlen(str);

	sort(str, str + s);

	int ans = 0;

	while (true) {

		bool flag = true;

		for (int i = 0; flag && i < s - 1; i++) {
			if (str[i] == str[i + 1]) {
				flag = false;
			}
		}

		if (flag) {

			ans++;

		}

		if (!next_permutation(str, str + s))break;

	}

	printf("%d\n", ans);

}