#include <stdio.h>
#include <memory.h>

int tree[1003][1003];
int n, m;

void update(int x, int y, int val){
	int y1;
	while (x <= n){
		y1 = y;
		while (y1 <= m){
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int read(int x, int y){ // return sum from 1,1 to x,y.
	int sum = 0;
	while (x){
		int y1 = y;
		while (y1){
			sum += tree[x][y1];
			y1 -= y1 & -y1;
		}
		x -= x & -x;
	}
	return sum;
}

int main(){
	while (scanf("%d %d", &n, &m) == 2 && n && m){

		memset(tree, 0, sizeof(tree));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				int a;
				scanf("%1d", &a);
				if(a)update(i, j, a);
			}
		}

		int s = 0;
		int ans = 0;
		for (int i = 1; i + s <= n; i++){
			for (int j = 1; j + s <= m;){
				int r1 = i, c1 = j;
				int r2 = i + s, c2 = j + s;
				//read(r1, c1, r2, c2) = read(r2, c2) - read(r2, c1 - 1) - read(r1 - 1, c2) + read(r1 - 1, c1 - 1);
				int S = read(r2, c2) - read(r2, c1 - 1) - read(r1 - 1, c2) + read(r1 - 1, c1 - 1);
				if (ans < S){
					if (S == (r2 - r1 + 1)*(c2 - c1 + 1)){
						ans = r2 - r1 + 1;
						s = r2 - r1 + 1;
						continue;
					}
				}
				j++;
			}
		}

		printf("%d\n", ans);
	}
}