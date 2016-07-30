#include <stdio.h>
#include <algorithm>

using namespace std;

int w[100003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%d", &w[i]);

	sort(w, w + n);

	int ans = 0;

	for (int i = 0; i < n; i++) {

		ans = max(w[i] * (n - i), ans);

	}

	printf("%d\n", ans);

}