#include <stdio.h>
#include <algorithm>

using namespace std;

int e[100003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%d", &e[i]);

	int c = 1;

	int ans = 0;

	for (int i = 1; i < n; i++) {
		if (e[i - 1] <= e[i])c++;
		else {
			ans = max(ans, c);
			c = 1;
		}
	}

	ans = max(ans, c);

	c = 1;
	for (int i = 1; i < n; i++) {
		if (e[i - 1] >= e[i])c++;
		else {
			ans = max(ans, c);
			c = 1;
		}
	}

	ans = max(ans, c);

	printf("%d\n", ans);

}