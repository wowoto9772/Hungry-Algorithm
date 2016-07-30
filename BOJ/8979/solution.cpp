#include <stdio.h>

class Olym {
public:
	int id, g, s, c;
}Cty[1003];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i<n; i++) {
		scanf("%d %d %d %d", &Cty[i].id, &Cty[i].g, &Cty[i].s, &Cty[i].c);
	}

	int ans = 0;

	for (int i = 0; i<n; i++) {
		if (Cty[i].id == k) {
			for (int j = 0; j<n; j++) {
				if (i == j)continue;
				if (Cty[i].g < Cty[j].g)ans++;
				else if (Cty[i].g == Cty[j].g) {
					if (Cty[i].s < Cty[j].s)ans++;
					else if (Cty[i].s == Cty[j].s) {
						if (Cty[i].c < Cty[j].c)ans++;
					}
				}
			}
		}
	}

	printf("%d\n", ans + 1);
}