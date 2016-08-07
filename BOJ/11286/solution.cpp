#include <stdio.h>
#include <functional>

#include <vector>
#include <queue>

using namespace std;

int main() {

	priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;

	int n;
	scanf("%d", &n);

	while (n--) {

		int v;
		scanf("%d", &v);

		if (!v) {

			if (pq.empty())printf("0\n");
			else {

				printf("%d\n", pq.top().second);
				pq.pop();

			}

		}
		else {

			pq.emplace(abs(v), v);

		}

	}

}