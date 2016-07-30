#include <stdio.h>
#include <queue>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	priority_queue <int> q;

	for (int i = 1; i <= n; i++) {
		int v;
		scanf("%d", &v);

		if (v) {
			q.emplace(v);
		}
		else {
			if (q.empty())printf("0\n");
			else {
				printf("%d\n", q.top());
				q.pop();
			}
		}
	}

}