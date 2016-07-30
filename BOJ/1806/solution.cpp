#include <stdio.h>

int S[100003];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		scanf("%d", &S[i]);
		S[i] += S[i - 1];
	}

	int ans = 100001;

	for (int i = 1; i <= n; i++){
		int l = i, r = n, md;
		while (l <= r){
			md = (l + r) / 2;
			int k = S[md] - S[i - 1];
			int x = md - i + 1;
			if (k < m)l = md + 1;
			else if (k >= m){
				r = md - 1;
				if (ans > x)ans = x;
			}
		}
	}

	if (ans == 100001)ans = 0;
	printf("%d\n", ans);
}