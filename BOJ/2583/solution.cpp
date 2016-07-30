#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

class ele{
public:
	int r, c;
	ele(){}
	ele(int a, int b){ r = a, c = b; }
};

bool chk[103][103];
int a[10003];
int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main(){
	int n, m, k;
	scanf("%d %d %d", &m, &n, &k);

	for (int i = 1; i <= k; i++){
		int a, b, x, y;
		scanf("%d %d %d %d", &a, &b, &x, &y);
		for (int g = a; g < x; g++){
			for (int s = b; s < y; s++){
				chk[g][s] = true;
			}
		}
	}

	int c = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (chk[i][j])continue;
			queue <ele> q;
			q.emplace(i, j);
			c++;

			int w = 1;
			chk[i][j] = true;

			while (!q.empty()){
				ele pp = q.front(); q.pop();
				for (int d = 0; d < 4; d++){
					ele psh = ele(pp.r + dr[d], pp.c + dc[d]);
					if (psh.r < 0 || psh.r >= n || psh.c < 0 || psh.c >= m)continue;
					if (chk[psh.r][psh.c])continue;
					chk[psh.r][psh.c] = true;
					w++;
					q.emplace(psh);
				}
			}
			a[c - 1] = w;
		}
	}

	sort(a, a + c);

	printf("%d\n", c);

	for (int i = 0; i < c; i++)printf("%d ", a[i]);
}