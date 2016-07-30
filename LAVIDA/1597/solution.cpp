#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <queue>

using namespace std;

class ele{
public:
	int a, b, c;
	bool operator<(const ele &A)const{
		if (c == A.c){
			if (a == A.a)return b < A.b;
			return a < A.a;
		}
		return c < A.c;
	}
}E[4000];

int Cv['z' + 3];
int di[4] = { 0, 0, -1, 1 };
int dj[4] = { -1, 1, 0, 0 };

int main(){
	int x = 0;
	for (int i = 'A'; i <= 'Z'; i++)Cv[i] = x++;
	for (int i = 'a'; i <= 'z'; i++)Cv[i] = x++;

	int t;
	while (scanf("%d", &t) == 1){

		while (t--){
			int R, C, K, D;
			scanf("%d %d %d %d", &R, &C, &K, &D);

			int top = 0;

			char str[32][32] = { 0 };

			for (int i = 0; i < R; i++)scanf("%s", str[i]);

			for (int i = 0; i < R; i++){ // make graph data
				for (int j = 0; j < C; j++){
					int now = i * C + j, nxt, h;
					for (int k = 0; k < 4; k++){
						int ni = i + di[k], nj = j + dj[k];
						if (ni >= 0 && ni < R && nj >= 0 && nj < C){
							h = abs(Cv[str[i][j]] - Cv[str[ni][nj]]);
							if (h <= K){
								nxt = ni * C + nj;
								if (str[i][j] >= str[ni][nj]){
									E[top].a = now, E[top].b = nxt, E[top].c = 1;
									top++;
								}
								else{
									E[top].a = now, E[top].b = nxt, E[top].c = h*h;
									top++;
								}
							}
						}
					}
				}
			}

			sort(E, E + top);

			int d[800];
			memset(d, 0x2f, sizeof(d));

			d[0] = 0;

			for (int i = 1; i <= R*C; i++){
				for (int j = 0; j < top; j++){
					if (d[E[j].b] > d[E[j].a] + E[j].c){
						d[E[j].b] = d[E[j].a] + E[j].c;
					}
				}
			}

			int ans = Cv[str[0][0]];

			for (int i = 1; i < R*C; i++){ // assume that this node is highest node.
				if (d[i] < D && ans < Cv[str[i / C][i%C]]){ // optimization
					int d2[800];
					memset(d2, 0x2f, sizeof(d2));

					d2[i] = 0;

					for (int j = 1; j <= R*C; j++){
						for (int j = 0; j < top; j++){
							if (d2[E[j].b] > d2[E[j].a] + E[j].c){
								d2[E[j].b] = d2[E[j].a] + E[j].c;
							}
						}
					}

					if (d[i] + d2[0] <= D){
						int a = Cv[str[i / C][i%C]];
						ans = ans < a ? a : ans;
					}
				}
			}

			printf("%d\n", ans);
		}
	}
}

/*
7
7 4 5 57
BCDE
AJKF
AIHG
AAAA
AOMK
AQSI
ACEG
=> 18

7 4 5 14
BCDE
AJKF
AIHG
AAAA
AOMK
AQSI
ACEG
==> 10

1 7 3 1000
ABCDEFK
==> 5



8 9 4 50
TRRVUXefk
bSNMOWcff
bRPNNQZip
XSRUTVcfj
WbZQPXZbV
XdYSRWVOP
feedVVcZR
XhfdZZefg

==> 28
*/