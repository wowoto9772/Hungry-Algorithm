#include <stdio.h>
#include <algorithm>

using namespace std;

int down[100003];
int up[100003];
int s[100003];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		s[i] += s[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		int l = i, r = n, m;
		while (l <= r) {
			m = (l + r) / 2;	
			int cmp = s[m] - s[i - 1];
			if (cmp <= k)l = m + 1;
			else
				r = m - 1;
		}
		while (m >= i && s[m] - s[i - 1] > k)m--;
		up[i] = m;
	}

}