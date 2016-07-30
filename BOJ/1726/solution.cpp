#include <stdio.h>
#include <queue>

using namespace std;

class dat{
public:
	int r, c, d, n;
	dat(){}
	dat(int x, int y, int z, int w){
		r = x, c = y, d = z, n = w;
	}
};

int a[103][103];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int change(int n){
	if (n == 1)return 1;
	else if (n == 2)return 3;
	else if (n == 3)return 2;
	else if (n == 4)return 0;
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++){
		for (int j = 1; j <= c; j++){
			scanf("%d", &a[i][j]);
		}
	}

	queue <dat> q;
	int s[3], e[3];
	for (int i = 0; i < 3; i++){
		scanf("%d", &s[i]);
	}
	for (int i = 0; i < 3; i++){
		scanf("%d", &e[i]);
	}
	s[2] = change(s[2]);
	e[2] = change(e[2]);

	bool chk[103][103][4] = { 0 };
	chk[s[0]][s[1]][s[2]] = true;
	q.emplace(s[0], s[1], s[2], 0);
	
	while (!q.empty()){
		dat pp = q.front(); q.pop();
		if (pp.r == e[0] && pp.c == e[1] && pp.d == e[2]){
			printf("%d\n", pp.n);
			break;
		}
		else{
			dat psh;
			for (int i = 1; i <= 3; i++){ // front 1, 2, 3
				psh = dat(pp.r + dr[pp.d] * i, pp.c + dc[pp.d] * i, pp.d, pp.n + 1);
				if (psh.c < 1 || psh.r < 1 || psh.r > r || psh.c > c)continue;
				if (chk[psh.r][psh.c][psh.d])continue;
				if (a[psh.r][psh.c])break;
				chk[psh.r][psh.c][psh.d] = true;
				q.emplace(psh);
			}

			// turn left or right
			for (int i = -1; i <= 1; i+=2){
				psh = pp;
				psh.d += i;
				if (psh.d == -1)psh.d = 3;
				else if (psh.d == 4)psh.d = 0;
				psh.n++;

				if (!chk[psh.r][psh.c][psh.d]){
					chk[psh.r][psh.c][psh.d] = true;
					q.emplace(psh);
				}
			}
		}
	}
}