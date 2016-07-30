#include <stdio.h>
#include <deque>

using namespace std;

int a[5000003];

int main() {

	int n, l;
	scanf("%d %d", &n, &l);

	deque <int> k;

	for (int i = 1; i <= n; i++) {

		scanf("%d", &a[i]);

		if (k.empty())k.push_front(a[i]);
		else {

			while (!k.empty() && k.back() > a[i]) {
				k.pop_back();
			}

			k.push_back(a[i]);

		}

		if (i > l) {
			if (k.front() == a[i - l])k.pop_front();
		}

		printf("%d ", k.front());

	}

}