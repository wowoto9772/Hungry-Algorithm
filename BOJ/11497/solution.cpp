#include <stdio.h>
#include <algorithm>

using namespace std;

int l[10003];
int s[10003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)scanf("%d", &l[i]);

		sort(l, l + n);

		int top = 0;

		int le = 0, ri = n - 1;

		while (top < n) {

			s[le++] = l[top++];
			if (top < n) {
				s[ri--] = l[top++];
			}

		}

		s[n] = s[0];

		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, abs(s[i] - s[i + 1]));
		}

		printf("%d\n", ans);

	}

}