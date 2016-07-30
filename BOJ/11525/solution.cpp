#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dp[10003] = { 0, 2 };

class ele {
public:

	int v, p;

	ele() {}
	ele(int a, int b) { v = a, p = b; }

};

int main() {

	for (int i = 2; i <= 10000; i++) {

		dp[i] = dp[i - 1] + i;
		int v = i;

		vector <int> k;

		for (int j = 2; j*j <= v; j++) {
			if (!(v%j)) {
				while (!(v%j)) {
					v /= j;
				}
				k.push_back(j);
			}
		}

		if (v != 1)k.push_back(v);

		queue <ele> q;
		
		for (int j = 0; j < k.size(); j++) {
			q.emplace(-k[j], j);
		}

		while (!q.empty()) {
			
			ele f = q.front(); q.pop();

			if (f.v < 0)dp[i] -= i / abs(f.v);
			else
				dp[i] += i / abs(f.v);

			for (int j = f.p + 1; j < k.size(); j++) {
				if (abs(f.v * (-k[j])) <= i) {
					q.emplace(f.v * (-k[j]), j);
				}
				else {
					break;
				}
			}

		}

	}

	int t;
	scanf("%d", &t);

	while (t--) {

		int a, n;
		scanf("%d %d", &a, &n);

		printf("%d %d\n", a, dp[n]);

	}

}