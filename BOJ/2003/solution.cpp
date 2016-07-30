#include <stdio.h>

int S[10003];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		scanf("%d", &S[i]);
		S[i] += S[i - 1];
	}

	int c = 0;

	for (int i = 1; i <= n; i++){
		int l = i, r = n, md;
		while (l <= r){
			md = (l + r) / 2;
			int k = S[md] - S[i - 1];
			if (k < m)l = md + 1;
			else if (k > m)r = md - 1;
			else{
				c++;
				break;
			}
		}
	}

	printf("%d\n", c);
}