#include <stdio.h>

#include <limits.h>

#include <queue>

#include <vector>

#include <algorithm>

using namespace std;

char str[103][103];

int chk[103][103][4];

int dr[] = {0, 1, 0, -1};
int dc[] = {-1, 0, 1, 0};

class ele{

	public:

		int r, c, d, m;

		ele(){}
		ele(int _r, int _c, int _d, int _m){
			r = _r, c = _c, d = _d, m = _m;
		}

		bool operator<(const ele &A)const{
			return m > A.m;
		}

};

int main(){

	int c, r;
	scanf("%d %d", &c, &r);

	for(int i=0; i<r; i++)for(int j=0; j<c; j++){
		for(int k=0; k<4; k++){
			chk[i][j][k] = INT_MAX;
		}
	}

	priority_queue <ele> q;

	int x, y;

	for(int i=0; i<r; i++){

		scanf("%s", str[i]);

		for(int j=0; j<c; j++){
			if(str[i][j] == 'C'){
				if(q.empty()){
					for(int k=0; k<4; k++){
						chk[i][j][k] = 0;
						q.emplace(i, j, k, 0);
					}
				}else{
					x = i, y = j;
				}
			}
		}

	}

	while(!q.empty()){

		ele f = q.top();q.pop();

		if(chk[f.r][f.c][f.d] < f.m)continue;

		vector <int> d = {f.d - 1, f.d, f.d + 1};

		if(d[0] < 0)d[0] += 4;

		if(d[2] > 3)d[2] -= 4;

		for(int i=0; i<d.size(); i++){

			ele g = {f.r, f.c, d[i], f.m};

			if(d[i] != f.d)g.m++;
			else{
				g.r += dr[f.d];
				g.c += dc[f.d];
			}

			if(0 <= g.r && g.r < r && 0 <= g.c && g.c < c){
				
				if(str[g.r][g.c] == '*')continue;
				
				if(chk[g.r][g.c][d[i]] > g.m){
					chk[g.r][g.c][d[i]] = g.m;
					q.emplace(g);
				}
			}

		}

	}

	int ans = INT_MAX;

	for(int i=0; i<4; i++){
		ans = min(ans, chk[x][y][i]);
	}

	printf("%d\n", ans);

}
