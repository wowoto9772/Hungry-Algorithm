#include <stdio.h>

char str[1000003];
int c[5];
int d[5];

int par['Z' + 3];

int main() {

	par['A'] = 0;
	par['C'] = 1;
	par['G'] = 2;
	par['T'] = 3;

	int n, k;
	scanf("%d %d", &n, &k);

	scanf("%s", str);
	for (int i = 0; i < 4; i++)scanf("%d", &c[i]);

	for (int i = 0; i < k; i++) {
		d[par[str[i]]]++;
	}

	int ans = 0;

	if (d[0] >= c[0] && d[1] >= c[1] && d[2] >= c[2] && d[3] >= c[3]) {
		ans++;
	}

	for (int i = k; i < n; i++) {
		d[par[str[i - k]]]--;
		d[par[str[i]]]++;
		if (d[0] >= c[0] && d[1] >= c[1] && d[2] >= c[2] && d[3] >= c[3]) {
			ans++;
		}
	}

	printf("%d\n", ans);

}