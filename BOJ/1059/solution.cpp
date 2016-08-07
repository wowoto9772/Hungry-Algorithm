#include <stdio.h>
#include <algorithm>

using namespace std;

int e[53];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)scanf("%d", &e[i]);

	sort(e + 1, e + n + 1);

	int k;
	scanf("%d", &k);

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (e[i] < k && k < e[i + 1]) {
			for (int j = e[i] + 1; j < e[i + 1]; j++) {
				for (int j2 = j + 1; j2 < e[i + 1]; j2++) {
					if (j <= k && k <= j2)ans++;
				}
			}
			break;
		}
	}

	printf("%d\n", ans);

}