#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n, a;
		scanf("%d", &n);

		int min = 101, max = 0;
		int v[8] = { 0 };

		for (int i = 1; i <= n; i++){
			scanf("%d", &a);
			while (a){
				for (int j = 7; j >= 1; j--){
					if (a >= 1 << j){
						v[j]++;
						a -= 1 << j;
					}
				}
			}
		}

		for (int i = 1; i <= 7; i++){
			if (v[i] > max)max = v[i];
			if (v[i] < min)min = v[i];
		}
		int c = 0, d = 0, e, f;
		for (int i = 1; i <= 7; i++){
			if (max == v[i]){
				c++;
				e = i;
			}
			if (min == v[i]){
				d++;
				f = i;
			}
		}

		if (c > 1 || d > 1)printf("Nagari\n");
		else
			printf("%d/%d\n", e, f);
	}
}