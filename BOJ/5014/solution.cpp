#include <stdio.h>
#include <limits.h>
#include <queue>

using namespace std;

int chk[1000003];

int main() {

	int f, s, g, u, d;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

	for (int i = 1; i <= f; i++)chk[i] = -1;

	queue <int> q;

	chk[s] = 0;
	q.push(s);

	while (!q.empty() && chk[g] == -1) {

		int x = q.front(); q.pop();

		if (x + u <= f) {
			if (chk[x + u] == -1) {
				chk[x + u] = chk[x] + 1;
				q.push(x + u);
			}
		}

		if (x - d >= 1) {
			if (chk[x - d] == -1) {
				chk[x - d] = chk[x] + 1;
				q.push(x - d);
			}
		}

	}

	if (chk[g] == -1)printf("use the stairs\n");
	else
		printf("%d\n", chk[g]);

}