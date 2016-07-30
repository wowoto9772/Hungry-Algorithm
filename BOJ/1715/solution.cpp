#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	priority_queue <int, vector <int>, greater <int> > q;


	while (n--) {

		int v;
		scanf("%d", &v);

		q.push(v);

	}

	int ans = 0;

	while (q.size() >= 2) {
		int p = q.top();
		q.pop();
		p += q.top();
		q.pop();

		ans += p;
		q.push(p);
	}

	printf("%d\n", ans);

}