#include <stdio.h>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int w[33];

int main() {

	int n, c;
	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}

	int mid = n / 2;

	ll ans = 1; // empty

	vector <ll> A;

	for (int i = 1; i < (1 << mid); i++) {

		ll x = 0;
		for (int j = 0; j < mid; j++) {
			if (i&(1<<j)) {
				x += w[j];
			}
		}

		if (x <= c) {
			ans++;
			A.push_back(x);
		}

	}

	vector <ll> B;

	for (int i = 1; i < (1 << (n - mid)); i++) {

		ll x = 0;

		for (int j = 0; j < n-mid; j++) {
			if (i&(1 << j)) {
				x += w[mid + j];
			}
		}
		
		if (x <= c) {
			ans++;
			B.push_back(x);
		}

	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < A.size() && B.size(); i++) {

		int le = 0, ri = B.size() - 1, m;
		while (le <= ri) {
			m = (le + ri) / 2;
			if (A[i] + B[m] <= c)le = m + 1;
			else
				ri = m - 1;
		}

		if (A[i] + B[m] > c)m--;

		if (m >= 0)ans += m + 1;
	}
	
	printf("%lld\n", ans);

}