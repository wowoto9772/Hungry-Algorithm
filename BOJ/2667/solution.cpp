#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

class ele{
public:
	int r, c;
	ele(){}
	ele(int a, int b){ r = a, c = b; }
};

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

char str[28][28];
bool chk[28][28];
int a[320];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%s", str[i]);

	queue <ele> q;

	int c = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (str[i][j] == '1' && !chk[i][j]){
				chk[i][j] = true;
				q.emplace(i, j);

				int d = 0;

				while (!q.empty()){
					ele pp = q.front(); q.pop();
					d++;
					for (int k = 0; k < 4; k++){
						ele psh = ele(pp.r + dr[k], pp.c + dc[k]);
						if (psh.r < 0 || psh.c < 0 || psh.r >= n || psh.c >= n)continue;
						if (chk[psh.r][psh.c])continue;
						if (str[psh.r][psh.c] == '0')continue;
						chk[psh.r][psh.c] = true;
						q.emplace(psh);
					}
				}

				a[c++] = d;
			}
		}
	}

	printf("%d\n", c);
	sort(a, a + c);

	for (int i = 0; i < c; i++)printf("%d\n", a[i]);
}