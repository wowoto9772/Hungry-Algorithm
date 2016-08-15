#include <stdio.h>
#include <string.h>

#include <algorithm>

#include <map>

using namespace std;


#define ll long long

char str[13];

int main() {

	scanf("%s", str);

	int s = strlen(str);

	map <char, int> c;

	int tp = 0;

	for (int i = 0; i < s; i++) {
		if (c.find(str[i]) == c.end()) {
			c[str[i]] = tp++;
		}
	}

	sort(str, str + s);

	int ans = 0;

	while (true) {

		bool flag = true;

		for (int i = 0; flag && i < s - 1; i++) {
			if (c[str[i]] == c[str[i + 1]]) {
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