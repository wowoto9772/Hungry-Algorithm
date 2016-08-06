#include <stdio.h>
#include <queue>

using namespace std;

bool chk[100003];

int main() {

	int n;
	scanf("%d", &n);

	deque <int> q;

	long long ans = 0;

	for (int i = 1; i <= n; i++) {

		int c;
		scanf("%d", &c);

		if (q.empty()) {
			q.push_back(c);
			chk[c] = true;
		}
		else {

			while (!q.empty() && chk[c]) {
				ans += q.size();
				chk[q.front()] = false;
				q.pop_front();
			}

			q.push_back(c);
			chk[c] = true;
		}

	}

	if (!q.empty()) {

		ans += (long long)q.size() * (q.size() + 1) / 2;

	}

	printf("%lld\n", ans);

}