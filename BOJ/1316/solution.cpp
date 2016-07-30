#include <stdio.h>
#include <string.h>

char str[103];

int main() {

	int t;
	scanf("%d", &t);

	int ret = 0;

	while (t--) {

		scanf("%s", str);

		int s = strlen(str);
		int c['z' + 3] = { 0 };

		for (int i = 0; i < s; i++)c[str[i]]++;

		bool flag = false;

		for (int i = 0; !flag && i < s; i++) {
			int k = c[str[i]];
			k--;
			for (int j = i + 1; j <= i + k; j++) {
				if (str[j] != str[i])flag = true;
			}
			if (!flag)i += k;
		}

		if (!flag)ret++;

	}

	printf("%d\n", ret);

}