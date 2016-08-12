#include <stdio.h>
#include <limits.h>
#include <string.h>

#include <string>
#include <queue>

#include <algorithm>

using namespace std;

#define LLMAX 92000000000000

#define ll long long

ll d[100003][2];

ll c[100003];

string out[100003][2];

char str[100003];

class ele {
public:

	int i, d;
	ll c;

	ele() {}
	ele(int _i, int _d, ll _c) {
		i = _i, d = _d, c = _c;
	}

	bool operator<(const ele &A)const {
		return c > A.c;
	}

};

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)scanf("%lld", &c[i]);

	ll ans = 0;

	for (int i = 1; i <= n; i++) {

		scanf("%s", str);

		out[i][0] = string(str);
		out[i][1] = out[i][0];
		reverse(out[i][1].begin(), out[i][1].end());

		if (i > 1)d[i][0] = d[i][1] = LLMAX;

	}

	priority_queue < ele > q;

	q.emplace(1, 0, 0);

	d[1][1] = c[1];
	q.emplace(1, 1, c[1]);

	while (!q.empty()) {

		ele f = q.top(); q.pop();

		if (d[f.i][f.d] < f.c)continue;

		if (f.i < n) {

			if (out[f.i][f.d] <= out[f.i + 1][0]) {

				if (d[f.i + 1][0] > f.c) {
					d[f.i + 1][0] = f.c;
					q.emplace(f.i + 1, 0, f.c);
				}

			}

			if (out[f.i][f.d] <= out[f.i + 1][1]) {

				if (d[f.i + 1][1] > f.c + c[f.i + 1]) {
					d[f.i + 1][1] = f.c + c[f.i + 1];
					q.emplace(f.i + 1, 1, f.c + c[f.i + 1]);
				}

			}

		}


	}

	ll flag = min(d[n][1], d[n][0]);
	printf("%lld\n", (flag == LLMAX) ? -1 : flag);

}