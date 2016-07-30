#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class dat1 {
public:
	int v;
	dat1() {}
	dat1(int a) { v = a; }
	bool operator<(const dat1 &A) const {
		return v > A.v;
	}
};

class dat2 {
public:
	int v;
	dat2() {}
	dat2(int a) { v = a; }
	bool operator<(const dat2 &A) const {
		return v < A.v;
	}
};

char cmd[10];

int main() {

	int n;
	scanf("%d", &n);

	priority_queue <dat1> ri;
	priority_queue <dat2> le;

	for (int i = 0; i < n; i++) {
		scanf("%s", cmd);
		if (!strcmp(cmd, "PUSH")) {

			int v;
			scanf("%d", &v);

			if (le.empty())le.emplace(v);
			else if (le.size() > ri.size()) {
				if (le.top().v < v) {
					ri.emplace(v);
				}
				else {
					ri.emplace(le.top().v);
					le.pop();
					le.emplace(v);
				}
			}
			else {
				int a[] = { le.top().v, ri.top().v, v };
				le.pop();
				ri.pop();
				sort(a, a + 3);
				le.emplace(a[0]);
				le.emplace(a[1]);
				ri.emplace(a[2]);
			}

			printf("%d\n", le.top().v);

		}
		else if (!strcmp(cmd, "POP")) {

			if (le.empty()) {
				printf("NO ITEM\n");
				continue;
			}
			le.pop();
			if (le.size() < ri.size()) {
				le.emplace(ri.top().v);
				ri.pop();
			}

			if (le.empty()) {
				printf("NO ITEM\n");
			}
			else {
				printf("%d\n", le.top().v);
			}



		}
		else {

			// size
			printf("%d\n", ri.size() + le.size());

		}
	}

}