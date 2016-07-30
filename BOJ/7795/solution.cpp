#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int A[20003], B[20003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int a, b;
		scanf("%d %d", &a, &b);

		for (int i = 0; i < a; i++)scanf("%d", &A[i]);
		for (int j = 0; j < b; j++)scanf("%d", &B[j]);

		B[b] = INT_MAX;

		sort(A, A + a);
		sort(B, B + b);

		int ans = 0;

		for (int i = 0; i < a; i++) {

			int p = lower_bound(B, B + b + 1, A[i]) - B;
			ans += p;

		}

		printf("%d\n", ans);

	}

}