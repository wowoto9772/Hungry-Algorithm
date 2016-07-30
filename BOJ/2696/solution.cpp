#include <stdio.h>

#include <queue>

#include <functional>

#include <algorithm>

using namespace std;

int e[10003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &e[i]);
		}

		printf("%d\n", n / 2 + 1);

		int cnt = 0;

		priority_queue <int> le;

		priority_queue < int, vector <int>, greater <int> >ri;

		for (int i = 1; i <= n; i++) {

			if (le.empty())le.push(e[i]);
			else {

				if (le.size() > ri.size()) {
					int a = le.top(); le.pop();
					le.push(min(a, e[i]));
					ri.push(max(a, e[i]));
				}
				else {
					int a[] = { le.top(), ri.top(), e[i] };
					le.pop(), ri.pop();

					sort(a, a + 3);

					le.push(a[0]);
					le.push(a[1]);
					ri.push(a[2]);

				}

			}

			if (i % 2) {

				cnt++;
				if (cnt == 11) {
					cnt = 1;
					printf("\n");
				}

				printf("%d ", le.top());

			}

		}

		printf("\n");

	}

}