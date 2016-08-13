#include <stdio.h>

int c[1003];

int main() {

	int n, m, l;
	scanf("%d %d %d", &n, &m, &l);

	int cur = 0;
	int cc = 0;

	while (++c[cur] < m) {

		cc++;

		int nxt;

		if (c[cur] & 1) {
			nxt = cur + l;
			if (nxt >= n)nxt -= n;
		}
		else {
			nxt = cur - l;
			if (nxt < 0)nxt += n;
		}

		cur = nxt;
	}

	printf("%d\n", cc);

}