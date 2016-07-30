#include <stdio.h>
#include <queue>

using namespace std;

bool lnk[5003][5003];

int sx[5001], sy[5001], dx[5001], dy[5001], d[5001];

int n;

void swp(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Process() {

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (d[i] == 1 && d[j] == 1) { // | |
				if (sx[i] == sx[j]) {
					if ((sy[i] <= sy[j] && sy[j] <= dy[i]) ||
						(sy[j] <= sy[i] && sy[i] <= dy[j])) {
						lnk[i][j] = lnk[j][i] = true;
					}
				}
			}
			else if (d[i] == 1 && d[j] == -1) { // | -
				if (sx[j] <= sx[i] && sx[i] <= dx[j]) {
					if (sy[i] <= sy[j] && sy[j] <= dy[i]) {
						lnk[i][j] = lnk[j][i] = true;
					}
				}
			}
			else if (d[i] == -1 && d[j] == 1) { // - |
				if (sy[j] <= sy[i] && sy[i] <= dy[j]) {
					if (sx[i] <= sx[j] && sx[j] <= dx[i]) {
						lnk[i][j] = lnk[j][i] = true;
					}
				}
			}
			else { // - -
				if (sy[i] == sy[j]) {
					if ((sx[i] <= sx[j] && sx[j] <= dx[i]) || 
						(sx[j] <= sx[i] && sx[i] <= dx[j])) {
						lnk[i][j] = lnk[j][i] = true;
					}
				}
			}
		}
	}
}

bool chk[5001];

class ele {
public:
	int v, c;
	ele() {}
	ele(int a, int b) { v = a, c = b; }
}S, D;


int main()
{

	int x;
	scanf("%d %d", &x, &x);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d %d %d", &x, &sx[i], &sy[i], &dx[i], &dy[i]);
		if (sx[i] == dx[i]) {
			d[i] = 1; // |
			if (sy[i] > dy[i])swp(&sy[i], &dy[i]);
		}
		else {
			d[i] = -1; // -
			if (sx[i] > dx[i])swp(&sx[i], &dx[i]);
		}
	}

	Process();

	scanf("%d %d %d %d", &S.v, &S.c, &D.v, &D.c);

	queue <ele> q;

	for (int i = 1; i <= n; i++) {
		if (sx[i] <= S.v && S.v <= dx[i] && sy[i] <= S.c && S.c <= dy[i]) {
			q.emplace(i, 1);
			chk[i] = true;
		}
	}

	while (!q.empty()) {
		ele f = q.front(); q.pop();

		if (sx[f.v] <= D.v && D.v <= dx[f.v] && sy[f.v] <= D.c && D.c <= dy[f.v]) {
			printf("%d\n", f.c);
			return 0;
		}

		for (int i = 1; i <= n; i++) {
			if(!chk[i]){
				if (lnk[f.v][i]) {
					chk[i] = true;
					q.emplace(i, f.c + 1);
				}
			}
		}
	}
}