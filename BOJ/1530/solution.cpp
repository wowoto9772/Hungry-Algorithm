#include <stdio.h>
#include <limits.h>

#include <vector>
#include <queue>
#include <map>

#include <algorithm>

using namespace std;

#define ll long long

int T[1033]; // max(1022)
int top;
int n;

void made(int a) {

	ll na = a * 10LL + 4LL;

	if (na <= n) {
		T[top++] = na;
		made(na);
	}

	na = a * 10LL + 7LL;

	if (na <= n) {
		T[top++] = na;
		made(na);
	}

}

map <int, int> dp;
map <int, int> rev;

int dy(int a) {

	if (!a)return 0;
	if (dp.find(a) != dp.end())return dp[a];

	dp[a] = INT_MAX / 8;

	for (int i = top - 1; i >= 0; i--) {

		if (T[i] <= a) {

			int v1 = T[i], v2 = a - T[i];
			int le = min(v1, v2);
			int ri = max(v1, v2);
			if (dp[a] > dy(le) + dy(ri)) {
				dp[a] = dy(le) + dy(ri);
				rev[a] = le;
			}

		}

	}

	return dp[a];

}

int main() {
	scanf("%d", &n);

	made(0);

	sort(T, T + top);

	for (int i = 0; i < top && T[i] <= n; i++) {
		dp[T[i]] = 1;
	}

	if (dy(n) >= INT_MAX / 8)printf("-1\n");
	else {
		vector <int> ans;
		queue <int> tmp;

		tmp.push(n);

		while (!tmp.empty()) {
			int f = tmp.front(); tmp.pop();
			if (dp[f] == 1) { // is shom number
				ans.push_back(f);
			}
			else {
				tmp.push(rev[f]);
				tmp.push(f - rev[f]);
			}
		}

		sort(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++)printf("%d ", ans[i]);
	}
}