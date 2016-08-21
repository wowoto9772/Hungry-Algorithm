#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

char str[53];

string wrd[53];

bool used[53];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		wrd[i] = string(str);
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {

		if (used[i])continue;

		ans++;

		string cmp = wrd[i] + wrd[i];

		for (int j = 0; j < cmp.size(); j++) {

			for (int k = i + 1; k <= n; k++) {

				if (used[k])continue;

				if (wrd[k].size() != wrd[i].size())continue;

				if (j + wrd[k].size() - 1 < cmp.size()) {
					if (cmp.substr(j, wrd[k].size()) == wrd[k]) {
						used[k] = true;
					}
				}

			}

		}

	}

	printf("%d\n", ans);

}