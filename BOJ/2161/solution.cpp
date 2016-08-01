#include <stdio.h>
#include <queue>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	deque <int> v;

	for (int i = 0; i < n; i++)v.push_back(i + 1);

	while (!v.empty()) {

		printf("%d ", v.front());
		v.pop_front();

		if (!v.empty()) {
			int k = v.front(); v.pop_front();
			v.push_back(k);
		}

	}

}