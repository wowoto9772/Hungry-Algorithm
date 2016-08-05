#include <stdio.h>
#include <functional>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class ele {
public:
	int s, e;
	bool operator<(const ele &A)const {
		if (s == A.s)return e < A.e;
		return s < A.s;
	}
}I[100003];

class dat {
public:
	int v, t;
	dat() {}
	dat(int a, int b) { v = a, t = b; }

	bool operator<(const dat&A)const {
		return t > A.t;
	}
};

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%d %d", &I[i].s, &I[i].e);
	sort(I, I + n);

	priority_queue <int, vector<int>, greater<int>> idle;
	priority_queue <dat> work;

	int cur = -1;
	int x = 0;

	for (int i = 0; i < n; i++) {

		if (cur < I[i].s)cur = I[i].s;

		while (!work.empty()) {
			if (work.top().t <= cur) {
				idle.push(work.top().v);
				work.pop();
			}
			else {
				break;
			}
		}

		if (idle.empty()) {
			idle.emplace(++x);
		}

		work.emplace(idle.top(), I[i].e);
		idle.pop();
	}

	printf("%d\n", x);

}