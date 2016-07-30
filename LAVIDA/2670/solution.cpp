#include <stdio.h>

double dp[403][103]; // must acquire x points, remain y chances
double dy(int x, int y){
	if (!x && !y)return 1.0;
	if (x < 0)return 0.0;
	if (dp[x][y] >= 0.0)return dp[x][y];

	dp[x][y] = 0.0;

	if (y){
		dp[x][y] += dy(x - 1, y) * 0.1;
		dp[x][y] += dy(x - 1, y - 1) * 0.2;
		dp[x][y] += dy(x, y - 1) * 0.7;
	}

	return dp[x][y];
}

int main(){
	for (int i = 0; i <= 400; i++){
		for (int j = 0; j <= 100; j++){
			dp[i][j] = -0.5;
		}
	}

	for (int i = 0; i <= 400; i++){
		for (int j = 0; j <= 100; j++){
			dy(i, j);
		}
	}

	int t;
	scanf("%d", &t);

	while (t--){
		int c, p;
		scanf("%d %d", &c, &p);

		double ans = 0.0;

		for (int j = p; j <= 400; j++){
			ans += dy(j, c);
		}
		printf("%.3lf\n", ans);
	}
}