#include <stdio.h>
#include <algorithm>

using namespace std;

int x[103];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)scanf("%d", &x[i]);

	while (true) {

		sort(x+1, x+1+n);
		
		int c = 0;

		for (int i = n; i >= 1; i--) {
			for (int j = i - 1; j >= 1; j--) {
				if (x[i] - x[j] > 0) {
					x[i] -= x[j];
					c++;
				}
			}
		}

		if (!c)break;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)ans += x[i];

	printf("%d\n", ans);

}