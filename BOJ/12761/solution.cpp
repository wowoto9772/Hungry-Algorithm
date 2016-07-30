#include <stdio.h>
#include <queue>

#define end 100000

using namespace std;

int chk[100003];

int main() {

	int a, b, n, m;
	scanf("%d %d %d %d", &a, &b, &n, &m);

	queue <int> q;
	q.push(n);

	while (!q.empty()) {
		
		int f = q.front(); q.pop();

		if (f == m)break;

		if (f*a <= end && !chk[f*a]) {
			chk[f*a] = chk[f] + 1;
			q.push(f*a);
		}
		if (f*b <= end && !chk[f*b]) {
			chk[f*b] = chk[f] + 1;
			q.push(f*b);
		}
		if (f + a <= end && !chk[f + a]) {
			chk[f + a] = chk[f] + 1;
			q.push(f + a);
		}
		if (f + b <= end && !chk[f + b]) {
			chk[f + b] = chk[f] + 1;
			q.push(f + b);
		}
		if (f - a >= 0 && !chk[f - a]) {
			chk[f - a] = chk[f] + 1;
			q.push(f - a);
		}
		if (f - b >= 0 && !chk[f - b]) {
			chk[f - b] = chk[f] + 1;
			q.push(f - b);
		}
		if (f + 1 <= end && !chk[f + 1]) {
			chk[f + 1] = chk[f] + 1;
			q.push(f + 1);
		}
		if (f - 1 >= 0 && !chk[f - 1]) {
			chk[f - 1] = chk[f] + 1;
			q.push(f - 1);
		}

	}

	printf("%d\n", chk[m]);

}