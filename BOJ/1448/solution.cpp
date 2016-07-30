#include <stdio.h>
#include <algorithm>

using namespace std;

int l[1000003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)scanf("%d", &l[i]);

	sort(l + 1, l + 1 + n);

	for (int i = n; i >= 3; i--) {
		if (l[i] < l[i - 1] + l[i - 2]) {
			printf("%d\n", l[i] + l[i - 1] + l[i - 2]);
			return 0;
		}
	}

	printf("-1\n");

}