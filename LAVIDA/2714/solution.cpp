#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class ele{
public:
	int x, y, z, f, t;
	ele(int a, int b, int c, int d, int e){ x = a, y = b, z = c, f = d, t = e; }
	bool operator<(const ele &A)const{
		return f > A.f;
	}
};

bool chk[53][53][53];
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };
int F[103];

int main(){
	int t;
	scanf("%d", &t);

	for (int T = 1; T <= t; T++){

		int N, M;
		scanf("%d %d", &N, &M);

		for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)for (int k = 0; k < N; k++)chk[i][j][k] = false;
		for (int i = 1; i <= 100; i++)F[i] = 0;

		vector <ele> dat;
		queue <ele> q;
		for (int i = 1; i <= M; i++){
			int x, y, z, f;
			scanf("%d %d %d %d", &x, &y, &z, &f);
			dat.emplace_back(x, y, z, f, 0);
			F[f]++;
			chk[x][y][z] = true;
		}

		sort(dat.begin(), dat.end());

		for (int i = 0; i < dat.size(); i++){
			q.emplace(dat[i]);
		}

		while (!q.empty()){
			ele pp = q.front(); q.pop();
			pp.t++;

			for (int i = 0; i < 6; i++){
				int nx = pp.x + dx[i];
				int ny = pp.y + dy[i];
				int nz = pp.z + dz[i];
				if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= N | nz >= N)continue;

				if (chk[nx][ny][nz])continue;

				chk[nx][ny][nz] = pp.t;
				F[pp.f]++;
				q.emplace(nx, ny, nz, pp.f, pp.t);
			}
		}

		sort(F + 1, F + 101);

		for (int i = 100; i >= 0; i--){
			if (F[i]){
				printf("#%d %d\n", T, F[i]);
				break;
			}
		}

	}
}


/*
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class ele{
public:
int x, y, z, p, t, i;
ele(int a, int b, int c, int d, int e, int f){ x = a, y = b, z = c, p = d, t = e, i = f; }
bool operator<(const ele &A)const{
return p > A.p;
}
};

int f[53][53][53];
bool chk[53][53][53];
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };
int F[103];

int main(){
int t;
scanf("%d", &t);

for (int T = 1; T <= t; T++){

int N, M;
scanf("%d %d", &N, &M);

for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)for (int k = 0; k < N; k++)chk[i][j][k] = false;
for (int i = 1; i <= 100; i++)F[i] = 0;

vector <ele> dat;
queue <ele> q;
for (int i = 1; i <= M; i++){
int x, y, z, f;
scanf("%d %d %d %d", &x, &y, &z, &f);
dat.emplace_back(x, y, z, f, 0, i);
F[i]++;
chk[x][y][z] = true;
}

sort(dat.begin(), dat.end());

for (int i = 0; i < dat.size(); i++){
q.emplace(dat[i]);
}

while (!q.empty()){
ele pp = q.front(); q.pop();
pp.t++;

for (int i = 0; i < 6; i++){
int nx = pp.x + dx[i];
int ny = pp.y + dy[i];
int nz = pp.z + dz[i];
if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= N | nz >= N)continue;

if (chk[nx][ny][nz])continue;

chk[nx][ny][nz] = pp.t;
F[pp.i]++;
q.emplace(nx, ny, nz, pp.p, pp.t, pp.i);
}
}

sort(F + 1, F + M + 1);
printf("#%d %d\n", T, F[M]);

}
}
*/