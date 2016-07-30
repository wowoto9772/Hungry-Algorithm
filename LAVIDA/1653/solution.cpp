#include <stdio.h>
#include <string.h>

#include <map>
#include <string>
#include <algorithm>

using namespace std;

char str[53];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		map <string, bool> chk;

		int ans = 0;

		for (int i = 1; i <= n; i++) {

			scanf("%s", str);

			int s = strlen(str);

			sort(str, str + s);

			string tmp = (string)str;

			if (chk.find(tmp) == chk.end()) {
				chk[tmp] = true;
				ans++;
			}
		}

		printf("%d\n", ans);

	}

}