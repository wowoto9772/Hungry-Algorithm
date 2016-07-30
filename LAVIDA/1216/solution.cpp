#include <stdio.h>

#include <queue>
#include <algorithm>

using namespace std;

int I[27][27];
int P[627];
int top;

int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)scanf("%d", &I[i][j]);

	queue <int> R, C;

	bool chk[27][27] = { 0 };

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (!chk[i][j] && I[i][j]){
				R.push(i), C.push(j);
				chk[i][j] = true;
				int ans = 0;
				while (!R.empty()){
					int r = R.front(), c = C.front();
					ans++;
					R.pop(), C.pop();
					for (int k = 0; k < 4; k++){
						int nr = r + dr[k], nc = c + dc[k];
						if (nr >= 1 && nr <= n){
							if (nc >= 1 && nc <= n){
								if (!chk[nr][nc] && I[nr][nc]){
									chk[nr][nc] = true;
									R.push(nr), C.push(nc);
								}
							}
						}
					}
				}
				P[top] = ans;
				top++;
			}
		}
	}

	sort(P, P + top);

	printf("%d\n", top);

	for (int i = 0; i < top; i++)printf("%d\n", P[i]);

}