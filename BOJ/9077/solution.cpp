#include <stdio.h>
#include <vector>
#include <map>

#include <algorithm>

using namespace std;

short pt[10003][10003];

int main() {


	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		vector <int> x(n), y(n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x[i], &y[i]);
			pt[x[i]][y[i]] = t + 1;
		}

		int s = 0;

		int ans = 0;

		for (int i = 0; i <= 10; i++) {
			for (int j = 0; j <= 10; j++) {
				s += pt[i][j] == (t + 1);
			}
		}

		int sv = s;

		for (int i = 10; i < 10000; i++) {
			if (i >= 11) {
				for (int j = 0; j <= 10; j++) {
					sv += pt[i][j] == (t + 1);
					sv -= pt[i - 11][j] == (t + 1);
				}
			}

			s = sv;

			ans = max(ans, s);

			for (int j = 11; j <= 10000; j++) {
				for (int k = i - 10; k <= i; k++) {
					s += pt[k][j] == (t + 1);
					s -= pt[k][j - 11] == (t + 1);
				}
				ans = max(ans, s);
			}
		}

		printf("%d\n", ans);

	}

}