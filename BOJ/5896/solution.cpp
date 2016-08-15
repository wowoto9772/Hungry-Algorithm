#include <stdio.h>

#include <vector>

#include <queue>

#include <functional>

using namespace std;

int pay[50003][2];

bool sold[50003];

#define ll long long
#define cost first
#define id second

int main() {

	int n, k;
	ll m;
	scanf("%d %d %lld", &n, &k, &m);

	for (int i = 1; i <= n; i++) {

		scanf("%d %d", &pay[i][1], &pay[i][0]);

	}

	priority_queue < int, vector <int>, greater<int> > res;

	priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair<int,int> > > low, high;

	for (int i = 1; i <= n; i++) {
		low.emplace(pay[i][0], i);
		high.emplace(pay[i][1], i);
	}

	for (int i = 1; i <= k; i++)res.push(0);

	int bought = 0;

	while (m > 0 && bought < n) {

		while (!low.empty() && sold[low.top().second])low.pop();
		while (!high.empty() && sold[high.top().second])high.pop();

		ll cst = res.top() + low.top().cost;

		if (cst < high.top().cost) {

			if (m < cst)break;

			m -= cst;

			// first use coupon, but at last do not use coupon
			res.pop();
			res.push(pay[low.top().id][1] - pay[low.top().id][0]);

			sold[low.top().id] = true;
			low.pop();

		}
		else {

			if (m < high.top().cost)break;

			m -= high.top().cost;
			sold[high.top().id] = true;

		}

		bought++;

	}

	printf("%d\n", bought);

}