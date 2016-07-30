#include <stdio.h>

long long T[1027][1027];

int N, M;

void update(int x, int y, int val){
	int y1;
	while (x <= N){
		y1 = y;
		while (y1 <= M){
			T[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

long long read(int x, int y){ // return sum from (1, 1) to (x, y)
	long long sum = 0;
	while (x){
		int y1 = y;
		while (y1){
			sum += T[x][y1];
			y1 -= y1 & -y1;
		}
		x -= x & -x;
	}
	return sum;
}

long long interval_sum(int r1, int c1, int r2, int c2){
	return read(r2, c2) - read(r2, c1 - 1) - read(r1 - 1, c2) + read(r1 - 1, c1 - 1);
}

int table[1027][1027];

// cf) make) dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + V[i][j]
//    value) S = dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];

void swp(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

int main(){
	int n, q;
	scanf("%d %d", &n, &q);

	N = M = n;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", &table[i][j]);
			update(i, j, table[i][j]);
		}
	}

	for (int i = 1; i <= q; i++){
		int a;
		scanf("%d", &a);

		if (a){
			int r1, c1, r2, c2;
			scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

			if (r1 > r2)swp(r1, r2);
			if (c1 > c2)swp(c1, c2);
			printf("%lld\n", interval_sum(r1, c1, r2, c2));
		}
		else{
			int x, y, v;
			scanf("%d %d %d", &x, &y, &v);

			update(x, y, -table[x][y]);
			update(x, y, v);
			table[x][y] = v;
		}
	}
}