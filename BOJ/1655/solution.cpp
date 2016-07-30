#include <stdio.h>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	priority_queue < int > le; // max heap
	priority_queue < int, vector<int>, greater<int> > ri; // min heap

	for (int i = 1; i <= n; i++) {
		int n;
		scanf("%d", &n);

		if (le.empty()) {
			le.push(n);
		}
		else if (le.size() > ri.size()) {
			int v = le.top(); le.pop();

			if (n > v) {
				int k = n;
				n = v;
				v = k;
			}

			le.push(n);
			ri.push(v);

		}
		else {
			int v[] = { le.top(), n, ri.top() };
			le.pop(), ri.pop();

			sort(v, v + 3);

			le.push(v[0]);
			le.push(v[1]);
			ri.push(v[2]);

		}
		printf("%d\n", le.top());
	}

}