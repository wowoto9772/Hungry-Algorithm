#include <stdio.h>
#include <limits.h>

int n;
int x[12], y[12];
int ans;
bool chk[12];

int A(int a){ return a < -a ? -a : a; }
int MD(int a, int b){ return A(x[a] - x[b]) + A(y[a] - y[b]); }

void GO(int c, int d){
	if (ans < d)return;

	chk[c] = true;

	bool f = false;

	for (int i = 1; i <= n; i++){
		if (!chk[i]){
			GO(i, d + MD(c, i));
			f = true;
		}
	}
	chk[c] = false;

	if (!f)ans = ans < d ? ans : d;
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d %d", &n, &x, &y);

		for (int i = 1; i <= n; i++)scanf("%d %d", &x[i], &y[i]);

		ans = INT_MAX;

		GO(0, 0);

		printf("%d\n", ans);
	}
}