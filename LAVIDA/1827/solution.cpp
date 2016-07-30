
/*
신입생은 한칸에 두 명 이상의 신입생이 동시에 존재 할수 있다.
갈수 없는 곳은 X
컴퓨터는 C
신입생은 S

특정 코스트 이하면, 매칭을
*/

#include <stdio.h>
#include <limits.h>
#include <memory.h>

#include <queue>

using namespace std;

#define max(a,b) a < b ? b : a
#define min(a,b) a < b ? a : b

char str[53][53];
int C[103], S[103], ct, st;
int flow[203][203], cap[203][203];

int d[2503][2503];
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { 1, -1, 0, 0 };

int maximum_flow(int source, int sink){
	int ret = 0;
	while (true){
		int r[203];
		memset(r, 0xff, sizeof(r));

		queue <int> Q;
		Q.push(source);
		r[source] = -2;

		while (!Q.empty() && r[sink] == -1){
			int f = Q.front(); Q.pop();
			for (int i = 0; i <= sink; i++){
				if (flow[f][i] < cap[f][i] && r[i] == -1){
					r[i] = f;
					Q.push(i);
				}
			}
		}

		if (r[sink] == -1)return ret;

		int flw = INT_MAX;

		for (int x = sink; r[x] >= 0; x = r[x]){
			int k = cap[r[x]][x] - flow[r[x]][x];
			flw = min(flw, k);
		}

		for (int x = sink; r[x] >= 0; x = r[x]){
			flow[r[x]][x] += flw;
			flow[x][r[x]] -= flw;
		}

		ret += flw;
	}
}

int main()
{
	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++){
		scanf("%s", str[i] + 1);
		for (int j = 1; j <= c; j++){
			if (str[i][j] == 'C'){
				C[++ct] = (i - 1)*c + j;
			}
			else if (str[i][j] == 'S'){
				S[++st] = (i - 1)*c + j;
			}
		}
	}

	memset(d, 0x2f, sizeof(d));

	for (int i = 1; i <= r; i++){
		for (int j = 1; j <= c; j++){
			if (str[i][j] == 'S'){
				int cur = (i - 1)*c + j;

				queue <int> X, Y, C;
				X.push(i), Y.push(j), C.push(0);
				bool chk[53][53] = { 0 };
				chk[i][j] = true;
				while (!X.empty()){
					int xf = X.front(), yf = Y.front(), cf = C.front();
					X.pop(), Y.pop(), C.pop();
					if (str[xf][yf] == 'C'){
						int nxt = (xf - 1)*c + yf;
						d[cur][nxt] = cf;
					}
					cf++;
					for (int k = 0; k < 4; k++){
						int nx = dr[k] + xf, ny = dc[k] + yf;
						if (nx < 1 || nx > r || ny < 1 || ny > c)continue;
						if (str[nx][ny] != 'X' && !chk[nx][ny]){
							chk[nx][ny] = true;
							X.push(nx), Y.push(ny), C.push(cf);
						}
					}
				}
			}
		}
	}

	for (int limit = 0; limit <= r*c; limit++){
		memset(flow, 0, sizeof(flow));
		memset(cap, 0, sizeof(cap));
		for (int i = 1; i <= st; i++){
			for (int j = 1; j <= ct; j++){
				if (d[S[i]][C[j]] <= limit){ // validate
					cap[0][i] = 1; // source
					cap[i][st + j] = 1;
					cap[st + j][st + ct + 1] = 1; // sink
				}
			}
		}

		int temp = maximum_flow(0, st + ct + 1);
		if (temp >= st){
			printf("%d\n", limit);
			break;
		}
	}

}