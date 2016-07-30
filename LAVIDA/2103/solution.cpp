#include <stdio.h>

int fun(int);

int main()
{

	int t;
	scanf("%d", &t);

	while (t--){
		int age[101] = { 0, };
		int n, x1, p;

		scanf("%d %d %d", &n, &x1, &p);

		int n_ = n;
		int c = x1;
		int ans;

		int aa = x1, bb = fun(aa), m = 1;
		bool used[101] = { 0 };
		used[aa] = true;

		while (aa != bb){
			m++;
			used[bb] = true;
			bb = fun(bb);
		}

		int k = n / m;
		n %= m;

		while (n--){
			age[c]++;
			c = fun(c);
		}

		int sum = 0, b = 0;

		while (sum < p) {
			sum += age[b];
			if (used[b] && n_ / m){
				sum += k;
			}
			ans = b;
			b++;
		}
		printf("%d\n", ans);
	}
}
int fun(int a) {
	return (a * 11 + 97) % 100;
}
