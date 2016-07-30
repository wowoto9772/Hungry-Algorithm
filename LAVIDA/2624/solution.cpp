#include <stdio.h>
#include <queue>

using namespace std;

int c[18][18];
int d[18][18];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)scanf("%1d", &c[i][j]);
		for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)scanf("%d", &d[i][j]);

		bool invalid = false;
		for (int i = 1; !invalid && i <= n; i++){
			for (int j = 1; !invalid && j <= m; j++){
				int mi = i - c[i][j];
				if (mi < 0)mi = 1;
				int Mi = i + c[i][j];
				if (Mi > n)Mi = n;
				for (int k = mi; !invalid && k <= Mi; k++){
					if (k == i)continue;
					if (c[i][j] == c[k][j])invalid = true;
				}

				int mj = j - c[i][j];
				if (mj < 0)mj = 1;
				int Mj = j + c[i][j];
				if (Mj > m)Mj = m;
				for (int k = mj; !invalid && k <= Mj; k++){
					if (k == j)continue;
					if (c[i][j] == c[i][k])invalid = true;
				}
			}
		}

		int dr[] = { -1, 0, 1, 0 };
		int dc[] = { 0, 1, 0, -1 };
		bool chk[18][18] = { 0 };
		for (int i = 1; !invalid && i <= n; i++){
			for (int j = 1; !invalid && j <= m; j++){
				if (chk[i][j])continue;

				queue <int> x, y;
				x.push(i);
				y.push(j);
				chk[i][j] = true;

				bool used[10] = { 0 };
				while (!x.empty() && !invalid){
					int ci = x.front(), cj = y.front();

					if (used[c[ci][cj]])invalid = true;
					used[c[ci][cj]] = true;

					x.pop(), y.pop();

					for (int k = 0; !invalid && k < 4; k++){
						int flag = d[ci][cj] & (1 << k);
						if (flag > 0){
							int ni = ci + dr[k];
							int nj = cj + dc[k];
							if (ni < 1 || ni > n)invalid = true;
							if (nj < 1 || nj > m)invalid = true;
							if (!chk[ni][nj]){
								chk[ni][nj] = true;
								x.push(ni);
								y.push(nj);
							}

						}
					}
				}
			}
		}

		if (invalid)printf("invalid\n");
		else{
			printf("valid\n");
		}
	}
}