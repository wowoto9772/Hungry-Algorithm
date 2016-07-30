#include <stdio.h>

int s[] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

int main() {

	int n;
	scanf("%d", &n);

	int tot = 0;

	for (int i = 1;; i++) {
		int l = s[i], r = s[i + 1] - 1;
		
		if (tot + (r - l + 1) * i >= n) {
			int m;
			while (l <= r) {
				m = (l + r) / 2;
				if (tot + (m - s[i] + 1)*i > n)r = m - 1;
				else
					l = m + 1;
			}

			if(tot + (m - s[i] + 1) * i > n)m--;

			tot += (m - s[i] + 1) * i;

			if (tot == n)printf("%d\n", m % 10);
			else {

				int d[10];
				int top = 0;
				int v = m + 1;
				while (v) {
					d[top++] = v % 10;
					v /= 10;
				}

				while (tot < n) {
					tot++;
					d[top--];
				}

				printf("%d\n", d[top]);
			}
			break;
		}
		else {
			tot += (r - l + 1) * i;
		}
	}

}