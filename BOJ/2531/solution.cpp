#include <stdio.h>
#include <algorithm>

using namespace std;

int I[33001];
int F[3001];

int main()
{

	int n, d, k, c;
	scanf("%d %d %d %d", &n, &d, &k, &c);

	int ans = 0, tmp = 1;
	F[c]++;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &I[i]);
		if (i <= k) {
			if (F[I[i]] == 0)tmp++;
			F[I[i]]++;
		}
	}

	for (int i = n + 1; i < n + k; i++) {
		I[i] = I[i - n];
	}

	for (int i = 2; i <= n; i++) {
		
		ans = max(ans, tmp);
		if (F[I[i - 1]] == 1)tmp--;
		F[I[i - 1]]--;
		if (F[I[i + k - 1]] == 0)tmp++;

		F[I[i + k - 1]]++;

	}

	printf("%d\n", ans);
}