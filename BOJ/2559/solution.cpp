#include <stdio.h>
#include <algorithm>

using namespace std;

int e[100003];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &e[i]);
	}

	int s = 0;

	for (int i = 0; i < k; i++)s += e[i];

	int ans = s;

	for (int i = k; i < n; i++) {
		s -= e[i - k];
		s += e[i];

		ans = max(ans, s);
	}

	printf("%d\n", ans);

}