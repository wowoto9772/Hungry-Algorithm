#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

class ele {
public:
	int v, p;
	ele() {}
	ele(int a, int b) { v = a, p = b; }
	bool operator<(const ele &A)const {
		if (v == A.v)return p > A.p;
		return v > A.v;
	}
};

int a[300003];

int main()
{

	int n, l;
	scanf("%d %d", &n, &l);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	priority_queue <ele> q;

	int p = 0;

	for (int i = 0; i < n; i++) {
		if (i)printf(" ");

		while (p && q.top().p <= i - l) {
			q.pop();
			p--;
		}
		q.emplace(a[i], i);
		p++;

		printf("%d", q.top().v);
	}
	return 0;
}