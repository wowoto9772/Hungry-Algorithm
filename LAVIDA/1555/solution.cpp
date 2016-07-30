#include <stdio.h>

int I[10] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2 };

int main()
{
	int t;
	scanf("%d", &t);

	for (int T = 1; T <= t; T++){
		int i, j, l, h, m, s;
		scanf("%d:%d:%d %d:%d:%d", &i, &j, &l, &h, &m, &s);

		int ans = 0;

		for (;;l++){
			if (l > 59){
				l -= 60;
				j++;
			}
			if (j > 59){
				j -= 60;
				i++;
			}
			if (i > 12)i -= 12;

			ans += I[i / 10] + I[i % 10];
			ans += I[j / 10] + I[j % 10];
			ans += I[l / 10] + I[l % 10];
			if (l == s && j == m && i == h){
				break;
			}
		}

		printf("Case #%d: %d\n", T, ans);
	}
}