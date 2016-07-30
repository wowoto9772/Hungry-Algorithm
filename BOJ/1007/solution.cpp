#include <stdio.h>
#include <limits.h>
#include <math.h>

#define ll long long

int x[23], y[23];
int n;
ll ans;

void dfs(int s, int c, int i){
	if (c == n / 2){
		ll x_ = 0, y_ = 0;
		for (int i = 0; i < n; i++){
			if (s & (1 << i)){
				x_ += x[i];
				y_ += y[i];
			}
			else{
				x_ -= x[i];
				y_ -= y[i];
			}
		}

		ll tmp = x_*x_ + y_*y_;

		if (ans > tmp)ans = tmp;
	}
	else{
		if (i == n)return;
		dfs(s | (1 << i), c + 1, i + 1);
		dfs(s, c, i + 1);
	}
}

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d", &n);

		for (int i = 0; i < n; i++){
			scanf("%d %d", &x[i], &y[i]);
		}

		ans = LLONG_MAX;

		dfs(0, 0, 0);

		printf("%.6lf\n", sqrt((double)ans));
	}
}