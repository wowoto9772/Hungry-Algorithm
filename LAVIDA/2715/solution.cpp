#include <stdio.h>
#include <queue>

using namespace std;

class ele{
public:
	int r, c, a, b, m;
	ele(){}

	ele(int x, int y, int dx, int dy, int z = 0){ r = x, c = y, a = dx, b = dy, m = z; }
	ele operator + (const ele &A)const{
		ele ret;
		ret.r = r + A.r;
		ret.c = c + A.c;
		ret.a = a + A.a;
		ret.b = b + A.b;
		ret.m = m + A.m;
		return ret;
	}
};

int b[53][53];
bool chk[53][53][53][53] = { 0 };
ele d[] = { { 0, -1, 0, -1 }, { 0, 1, 0, 1 }, { -1, 0, -1, 0 }, { 1, 0, 1, 0 } };

bool check(ele a, bool x){
	if (chk[a.r][a.c][a.a][a.b] == x)return true;
	else
		chk[a.r][a.c][a.a][a.b] = x;
	return false;
}

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		int r, c;
		scanf("%d %d", &r, &c);

		ele me;

		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= c; j++){
				scanf("%d", &b[i][j]);
				if (b[i][j] == 3)me.r = i, me.c = j;
				else if (b[i][j] == 4)me.a = i, me.b = j;
				for (int a = 1; a <= r; a++){
					for (int b = 1; b <= c; b++){
						chk[i][j][a][b] = false;
					}
				}
			}
		}

		me.m = 1;

		queue <ele> q;


		q.emplace(me);
		check(me, true);

		bool end = false;

		while (!q.empty()){
			ele pp = q.front(); q.pop();
			if (b[pp.r][pp.c] == 2){
				printf("%d\n", pp.m);
				end = true;
				break;
			}
			for (int i = 0; i < 4; i++){
				ele psh = pp + d[i];
				psh.m++;
				if (psh.m >= 10)break;
				if (psh.r < 1 || psh.c < 1 || psh.r > r || psh.c > c || b[psh.r][psh.c] == 1)psh.r = pp.r, psh.c = pp.c;
				if (psh.a < 1 || psh.b < 1 || psh.a > r || psh.b > c || b[psh.a][psh.b] == 2 || b[psh.a][psh.b] == 1)psh.a = pp.a, psh.b = pp.b;
				if (check(psh, true))continue;
				check(psh, true);
				q.emplace(psh);
			}
		}

		if (!end)printf("-1\n");
	}

}