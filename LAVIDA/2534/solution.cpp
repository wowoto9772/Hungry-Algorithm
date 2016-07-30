#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

char str[53];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		string ans;
		int x = 0;

		for (int i = 1; i <= n; i++) {
			scanf("%s", str);

			int a, b;
			scanf("%d %d", &a, &b);
			if (x < a + b)x = a + b, ans = string(str);
		}

		printf("%s\n", ans.c_str());

	}

}