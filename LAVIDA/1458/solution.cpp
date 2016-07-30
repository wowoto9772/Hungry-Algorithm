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

	bool operator<(const ele &A)const {
		return c > A.c;
	}
};

int main() {


	int n;
	while (scanf("%d", &n) == 1) {

		priority_queue <ele> q;
		q.emplace(1, 0, 0);

		while (!q.empty()) {

			ele f = q.top(); q.pop();

			if (f.a == n || f.b == n) {

				printf("%d\n", f.c);
				break;

			}
			else {

				ele g;

				g = { f.a, 2*f.a, f.c + 1 };
				if (g.a <= 2 * n) {
					q.emplace(g);
				}

				if (f.a != f.b) {
					g = { 2 * f.b, f.b, f.c + 1 };
					if (g.b <= 2 * n) {
						q.emplace(g);
					}
				}


				g = { f.a + f.b, f.b, f.c + 1 };

				if (g.a <= 2 * n) {
					q.emplace(g);
				}

				g = { f.a, f.a + f.b, f.c + 1 };

				if (g.b <= 2 * n) {
					q.emplace(g);
				}

				g = { f.a - f.b, f.b, f.c + 1 };
				if (g.a > 0) {
					q.emplace(g);
				}

				g = { f.a, f.b - f.a, f.c + 1 };
				if (g.b > 0) {
					q.emplace(g);
				}

			}
		}

	}

}