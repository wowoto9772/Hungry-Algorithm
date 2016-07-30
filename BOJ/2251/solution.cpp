#include <stdio.h>
#include <queue>

using namespace std;

class ele {
public:
	int a, b, c;
	ele() {}
	ele(int a_, int b_, int c_) {
		a = a_, b = b_, c = c_;
	}
};

bool chk[203][203][203];

bool w[203];

int main() {

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	queue <ele> q;

	q.emplace(0, 0, c);

	chk[0][0][c] = true;

	while (!q.empty()) {

		ele f = q.front(); q.pop();

		if (!f.a)w[f.c] = true;

		ele g;

		if (f.a < a) {

			g = f;

			int bb = min(a - g.a, g.b);
			g.a += bb;
			g.b -= bb;

			if (!chk[g.a][g.b][g.c]) {
				chk[g.a][g.b][g.c] = true;
				q.emplace(g);
			}

			g = f;

			int cc = min(a - g.a, g.c);
			g.a += cc;
			g.c -= cc;

			if (!chk[g.a][g.b][g.c]) {
				chk[g.a][g.b][g.c] = true;
				q.emplace(g);
			}

		}

		if (f.b < b) {

			g = f;

			int aa = min(b - g.b, g.a);
			g.a -= aa;
			g.b += aa;

			if (!chk[g.a][g.b][g.c]) {
				chk[g.a][g.b][g.c] = true;
				q.emplace(g);
			}

			g = f;

			int cc = min(b - g.b, g.c);
			g.c -= cc;
			g.b += cc;

			if (!chk[g.a][g.b][g.c]) {
				chk[g.a][g.b][g.c] = true;
				q.emplace(g);
			}

		}

		if (f.c < c) {

			g = f;

			int aa = min(c - g.c, g.a);
			g.a -= aa;
			g.c += aa;

			if (!chk[g.a][g.b][g.c]) {
				chk[g.a][g.b][g.c] = true;
				q.emplace(g);
			}

			g = f;

			int bb = min(c - g.c, g.b);
			g.b -= bb;
			g.c += bb;

			if (!chk[g.a][g.b][g.c]) {
				chk[g.a][g.b][g.c] = true;
				q.emplace(g);
			}

		}

	}

	for (int i = 0; i <= 200; i++)if (w[i])printf("%d ", i);

}