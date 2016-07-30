#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

char str[1003];

int main() {

	int t;
	scanf("%d", &t);

	int tc = 0;

	while (t--) {

		scanf("%s", str);

		int s = strlen(str);

		string ans;
		for (int i = 0; i < s; i++) {
			if (ans.empty()) {
				ans = str[i];
			}
			else {
				if (ans[0] > str[i]) {
					ans += str[i];
				}
				else if (ans[0] <= str[i]) {
					ans = str[i] + ans;
				}
			}
		}

		printf("Case #%d: %s\n", ++tc, ans.c_str());

	}

}