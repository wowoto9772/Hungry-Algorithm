#include <stdio.h>

long long hi[100003];
long long p[100003];

int main()
{ 
	int n;
	while (scanf("%d", &n) == 1 && n) {

		int top = 1;

		scanf("%lld", &hi[1]);
		p[1] = 1;

		long long ans = 0;
		for (int i = 2; i <= n; i++) {
			long long a;
			scanf("%lld", &a);
			if (hi[top] < a) {
				hi[++top] = a;
				p[top] = i;
			}
			else if (hi[top] > a) {

				long long r;

				while (hi[top] > a) {
					r = p[top];
					long long tmp = (i - p[top]) * hi[top];
					ans = ans < tmp ? tmp : ans;
					top--;
				}

				hi[++top] = a;
				p[top] = r;
			}
		}

		while (top != 0) {
			long long tmp = (n - p[top] + 1) * hi[top];
			ans = ans < tmp ? tmp : ans;
			top--;
		}

		printf("%lld\n", ans);
	}
}