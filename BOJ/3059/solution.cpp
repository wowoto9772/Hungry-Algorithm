#include <stdio.h>
#include <string.h>

char str[1003];

int main() {

	int t;
	scanf("%d", &t);

	int tot = 0;

	for (int i = 'A'; i <= 'Z'; i++)tot += i;

	while (t--) {

		scanf("%s", str);

		int s = strlen(str);

		bool chk['Z' + 3] = { 0 };

		for (int i = 0; i < s; i++)chk[str[i]] = true;

		int ans = tot;
		for (int i = 'A'; i <= 'Z'; i++)if (chk[i])ans -= i;

		printf("%d\n", ans);

	}

}