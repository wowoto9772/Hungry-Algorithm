#include <stdio.h>

int S[103], V[103];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++)scanf("%d", &S[i]);
		for (int i = 1; i <= n; i++)scanf("%d", &V[i]);

		while (m--){
			int min = 3000101, s;
			for (int i = 1; i <= n; i++){
				if (min > S[i]){
					min = S[i];
					s = i;
				}
			}
			S[s] += V[s];
		}

		int ans = 3000101;

		for (int i = 1; i <= n; i++)ans = ans < S[i] ? ans : S[i];

		printf("%d\n", ans);
	}
}