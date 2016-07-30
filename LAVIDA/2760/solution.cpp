#include <stdio.h>
#include <limits.h>
#include <queue>
#include <algorithm>

using namespace std;

#define ll long long

class point {
public:
	int x, y;
}p[10007];

class ele {
public:
	ele() {}
	ele(int a_, int c_) { a = a_, c = c_; }
	int a, c;
	bool operator<(const ele &A)const {
		return c > A.c;
	}
};

ll dist(point a, point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}


ll d[10007];
bool chk[10007];

#define src 0
#define snk (2*n+1)

int main() {

	scanf("%d %d %d %d", &p[src].x, &p[src].y, &p[10004].x, &p[10004].y);

	int n;
	scanf("%d", &n);

	p[snk] = p[10004];

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &p[2 * i - 1].x, &p[2 * i - 1].y);
		scanf("%d %d", &p[2 * i].x, &p[2 * i].y);
	}

	for (int i = 1; i <= snk; i++)d[i] = LLONG_MAX;
	d[snk] = dist(p[src], p[snk]);

	priority_queue <ele> q;

	q.emplace(0, 0);

	while (!q.empty()) {

		ele f = q.top(); q.pop();

		if (chk[f.a])continue;
		chk[f.a] = true;

		d[snk] = min(d[snk], f.c + dist(p[f.a], p[snk]));

		for (int i = 1; i <= n; i++) {
			int nc = f.c + dist(p[i * 2 - 1], p[f.a]);
			if (chk[i * 2 - 1])continue;
			if (d[i * 2 - 1] > nc) {
				d[i * 2 - 1] = nc;
				q.emplace(i * 2 - 1, nc);
			}

			int cc = f.c + dist(p[i * 2], p[f.a]);
			if (nc > cc)nc = cc;

			if (d[i * 2] > nc) {
				d[i * 2] = nc;
				q.emplace(i*2, nc);
			}
		}

	}

	printf("%lld\n", d[snk]);

}