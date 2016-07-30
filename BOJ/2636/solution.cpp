#include <stdio.h>
#include <queue>

using namespace std;

class ele{
public:
	int r, c;
	ele(){}
	ele(int a, int b){ r = a, c = b; }
};

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int a[103][103];
bool del[103][103];
bool chk[103][103];

int main(){

	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++){
		for (int j = 1; j <= c; j++){
			scanf("%d", &a[i][j]);
		}
	}

	int ans = 0, lst = 0;

	while (true){
		queue <ele> q;

		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= c; j++){
				if (del[i][j]){
					a[i][j] = 0;
					del[i][j] = false;
				}
				chk[i][j] = false;
			}
		}

		for (int i = 1; i <= r; i++){
			chk[i][1] = chk[i][c] = true;
			q.emplace(i, 1);
			q.emplace(i, c);
		}
		for (int i = 1; i <= c; i++){
			chk[r][i] = chk[1][i] = true;
			q.emplace(r, i);
			q.emplace(1, i);
		}

		int cnt = 2 * r + 2 * c - 4;
		int ccnt = 0; // cheese cnt

		while (!q.empty()){
			ele pp = q.front(); q.pop();
			for (int i = 0; i < 4; i++){
				ele psh = ele(pp.r + dr[i], pp.c + dc[i]);
				if (psh.r < 1 || psh.c < 1 || psh.r > r || psh.c > c)continue;
				if (chk[psh.r][psh.c])continue;
				if (a[psh.r][psh.c]){
					del[psh.r][psh.c] = true;
					chk[psh.r][psh.c] = true;
					ccnt++;
				}
				else{
					chk[psh.r][psh.c] = true;
					cnt++;
					q.emplace(psh);
				}
			}
		}

		if (cnt == r*c)break;
		else{
			lst = ccnt;
			ans++;
		}
	}

	printf("%d\n%d\n", ans, lst);
}