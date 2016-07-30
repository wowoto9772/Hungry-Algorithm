#include <stdio.h>
#include <algorithm>

using namespace std;

class ele {
public:
	int l, r;
	bool operator<(const ele &A)const {
		if (l == A.l)return r > A.r;
		return l < A.l;
	}
}I[500003];

int dp[500003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%*d %d %d", &I[i].l, &I[i].r);
	}

	sort(I, I + n);

	int top = 0;
	int ans = 0;

	for (int i = 0; i < n; i++) {

		if (i && I[i].r == I[i - 1].r && I[i].l == I[i - 1].l)continue;

		if (i == 0 || I[dp[top - 1]].r >= I[i].r) {
			dp[top] = i;

			top++;
			ans = max(ans, top);

		}
		else {

			int l = 0, r = top - 1, m;

			while (l <= r) {
				m = (l + r) / 2;
				if (I[dp[m]].r < I[i].r) {
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}

			ans = max(ans, top);
			
			while (I[dp[m]].r >= I[i].r) {
				m++;
			}

			dp[m] = i;
			// top = m + 1;
		}
	}

	printf("%d\n", ans);

	return 0;
}