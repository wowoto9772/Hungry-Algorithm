#include <stdio.h>

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	int x;
	scanf("%d", &x);

	int l = 1, r = m;

	int ans = 0;

	for (int i = 1; i <= x; i++) {

		int p, s = 0;
		scanf("%d", &p);

		if(r < p){
			s = p - r;
			l += s, r += s;
		}
		else if (p < l) {
			s = l - p;
			l -= s, r -= s;
		}

		ans += s;

	}

	printf("%d\n", ans);

}