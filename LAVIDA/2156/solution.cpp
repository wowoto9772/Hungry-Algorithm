#include <stdio.h>
#include <memory.h>

#include <queue>

using namespace std;

class ele{
public:
	int x, y, c, n;
};

bool chk[102][102][102] = { 0 };

int dx[] = { 1, 1, -1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 0, 0, 1, 1, -1, -1 };
//int drx[] = { 1, 1, -1, -1, 1, -1, 1, -1};
//int dry[] = { 1, -1, 1, -1, 1, 1, -1, -1}; 
int drx[] = { 0, 0, 0, 0, 1, -1, 1, -1 };
int dry[] = { 1, -1, 1, -1, 0, 0, 0, 0 };

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, k;
		scanf("%d %d", &n, &k);

		char L[5] = { 0 }, R[5] = { 0 };
		scanf("%s %s", L, R);

		ele psh, pop, l, r;
		l.y = L[1] - '0', r.y = R[1] - '0';
		l.x = L[0] - 'a' + 1, r.x = R[0] - 'a' + 1;

		psh = l;
		psh.c = 1, psh.n = 0;

		queue <ele> Q;
		Q.push(psh);

		bool f = false;
		
		memset(chk, 0, sizeof(chk));

		while (!Q.empty()){
			pop = Q.front(); Q.pop();
			if (pop.x == r.x && pop.y == r.y && pop.n == n){
				f = true;
				break;
			}
			psh.c = pop.c + 1, psh.n = pop.n+1;
			if (psh.n <= n){
				for (int i = 0; i < 8; i++){
					int c = pop.c % k;
					if (!c)c = k;
					psh.x = pop.x + c * dx[i] + drx[i];
					psh.y = pop.y + c * dy[i] + dry[i];
					if (psh.x >= 1 && psh.x <= 8){
						if (psh.y >= 1 && psh.y <= 8){
							if (!chk[psh.x][psh.y][psh.c]){
								Q.push(psh);
								chk[psh.x][psh.y][psh.c] = true;
							}
						}
					}
				}
			}
		}

		if (f)printf("Yes\n");
		else
			printf("No\n");
	}
}