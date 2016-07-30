#include <stdio.h>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	vector <int> a(n), b(n), c(n), d(n);

	for (int i = 0; i < n; i++)scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);

	vector <int> X(n*n), Y(n*n);

	int top = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Y[top] = (c[i] + d[j]);
			X[top] = (a[i] + b[j]);
			top++;
		}
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());

	ll ans = 0;

	int l = 0, r = X.size() - 1;

	ll x, y;
	x = y = 1;

	while (l < X.size() && r >= 0) {
		while (l + 1 < X.size() && X[l] == X[l + 1])x++, l++;
		while (r - 1 >= 0 && Y[r] == Y[r - 1])r--, y++;
		if (X[l] + Y[r] == 0) {
			ans += x * y;
			l++;
			r--;
			x = y = 1;
		}
		else if (X[l] + Y[r] > 0) {
			r--;
			y = 1;
		}
		else {
			l++;
			x = 1;
		}
	}

	printf("%lld\n", ans);

}