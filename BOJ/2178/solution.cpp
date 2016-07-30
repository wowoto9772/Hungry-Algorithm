#include <stdio.h>
#include <queue>

using namespace std;

class ele{
public:
	int r, c, m;
	ele(){}
	ele(int a, int b, int c_){ r = a, c = b, m = c_; }
};

int a[103][103];
int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };
bool chk[103][103];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)scanf("%1d", &a[i][j]);

	queue <ele> q;
	q.emplace(0, 0, 1);
	chk[0][0] = true;

	while (!q.empty()){
		ele pp = q.front(); q.pop();
		if (pp.r == n - 1 && pp.c == m - 1){
			printf("%d\n", pp.m);
			break;
		}
		else{
			for (int i = 0; i < 4; i++){
				ele psh = ele(pp.r + dr[i], pp.c + dc[i], pp.m + 1);
				if (psh.r < 0 || psh.c < 0 || psh.r >= n || psh.c >= m)continue;
				if (chk[psh.r][psh.c])continue;
				if (!a[psh.r][psh.c])continue;

				chk[psh.r][psh.c] = true;
				q.emplace(psh);
			}
		}
	}
}