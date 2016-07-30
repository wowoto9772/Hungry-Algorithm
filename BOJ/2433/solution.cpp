#include <stdio.h>

#include <queue>
#include <vector>

#include <functional>

using namespace std;

int e[1000003];

int main() {

	int n, m, c;
	scanf("%d %d %d", &n, &m, &c);

	priority_queue < pair<int, int> > ma;
	priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > mi;

	for (int i = 0; i < n; i++)scanf("%d", &e[i]);

	for (int i = 0; i < m; i++) {

		mi.push(make_pair(e[i], i));
		ma.push(make_pair(e[i], i));

	}

	bool x = false;

	if (ma.top().first - mi.top().first <= c) {
		printf("%d\n", 1);
		x = true;
	}

	for (int i = m; i < n; i++) {

		while (!ma.empty() && ma.top().second <= i - m)ma.pop();
		while (!mi.empty() && mi.top().second <= i - m)mi.pop();

		mi.push(make_pair(e[i], i));
		ma.push(make_pair(e[i], i));

		if (ma.top().first - mi.top().first <= c) {
			printf("%d\n", i - m + 2);
			x = true;
		}

	}

	if (!x)printf("NONE\n");

}