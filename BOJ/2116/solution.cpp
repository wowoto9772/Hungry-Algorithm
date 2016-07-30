#include <stdio.h>

int d[10001][7];

int nxt(int a) {
	if (a == 1)return 6;
	else if (a == 2)return 4;
	else if (a == 3)return 5;
	else if (a == 6)return 1;
	else if (a == 5)return 3;
	else if (a == 4)return 2;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			scanf("%d", &d[i][j]);
		}
	}

	int cur, ncur;
	int ans = 0;
	for (int i = 1; i <= 6; i++) {
		
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			int tmp = 0;

			if (j == 1) {
				for (int k = 1; k <= 6; k++) {
					if (k == i || k == nxt(i))continue;
					if (d[j][k] >= tmp)tmp = d[j][k];
				}
				sum += tmp;
				cur = nxt(i);
				continue;
			}

			for (int k = 1; k <= 6; k++) {
				if (d[j - 1][nxt(cur)] == d[j][k]) { 
					ncur = k; 
					break; 
				}
			}

			cur = ncur;

			for (int k = 1; k <= 6; k++) {
				if (k == cur || k == nxt(cur))continue;
				if (d[j][k] >= tmp)tmp = d[j][k];
			}

			sum += tmp;
		}

		if (ans <= sum)ans = sum;
	}
	
	printf("%d\n", ans);
}