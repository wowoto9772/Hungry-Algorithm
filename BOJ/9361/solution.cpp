#include <stdio.h>
#include <algorithm>
using namespace std;

int c[31], a[31];

int main() {

	int t;
	scanf("%d", &t);

	for (int tc = 1; tc <= t; tc++) {

		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &c[i]);
			a[i] = c[i];
		}

		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (a[i]>a[j])swap(a[i], a[j]);

		int cost = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; i != j && j <= n; j++)
				if (a[i] == c[j])cost += abs(j - i);

		printf("Case #%d: %d\n", tc, cost);
	}
}
