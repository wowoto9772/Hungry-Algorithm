#include <stdio.h>
#include <map>
#include <set>

using namespace std;

int main() {

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	set <int> key;
	map <int, int> val;

	key.insert(-3);
	key.insert(1000000007);

	for (int i = 1; i <= n; i++) {

		int x, y;
		scanf("%d %d", &x, &y);

		key.insert(x);
		val[x] = y;

	}

	for (int i = 1; i <= m; i++) {

		int t;
		scanf("%d", &t);

		if (t == 1) {
			int x, y;
			scanf("%d %d", &x, &y);

			key.insert(x);
			val[x] = y;
		}
		else if (t == 2) {
			int x, y;
			scanf("%d %d", &x, &y);

			if (val.find(x) != val.end())val[x] = y;
			else {

				set <int> ::iterator ri = key.lower_bound(x);
				set <int> ::iterator le = ri;
				le--;

				int cand[2];
				int top = 0;

				if (*le > 0) {
					if (abs(*le - x) <= k) {
						cand[top++] = *le;
					}
				}

				if (*ri <= 1000000000) {
					if (abs(*ri - x) <= k) {
						cand[top++] = *ri;
					}
				}

				if (top == 2) {
					if (abs(cand[0] - x) > abs(cand[1] - x))val[cand[1]] = y;
					else if (abs(cand[0] - x) < abs(cand[1] - x))val[cand[0]] = y;
				}
				else if (top == 1) {
					val[cand[0]] = y;
				}

			}
		}
		else {

			int x;
			scanf("%d", &x);

			set <int> ::iterator ri = key.lower_bound(x);

			if (*ri == x) {
				printf("%d\n", val[x]);
			}
			else {

				set <int> ::iterator le = ri;
				le--;

				int cand[2];
				int top = 0;

				if (*le > 0) {
					if (abs(*le - x) <= k) {
						cand[top++] = *le;
					}
				}

				if (*ri <= 1000000000) {
					if (abs(*ri - x) <= k) {
						cand[top++] = *ri;
					}
				}

				if (!top)printf("-1\n");
				else {
					if (top == 2) {
						if (abs(cand[0] - x) == abs(cand[1] - x))printf("?\n");
						else if (abs(cand[0] - x) > abs(cand[1] - x))printf("%d\n", val[cand[1]]);
						else
							printf("%d\n", val[cand[0]]);
					}
					else {
						printf("%d\n", val[cand[0]]);
					}
				}

			}

		}

	}

}