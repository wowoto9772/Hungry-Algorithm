#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class ele{
public:
	int r, c, m;
	ele(){}
	ele(int r_, int c_, int m_){ r = r_, c = c_, m=m_; }

	bool operator<(const ele &A)const{
		return m > A.m;
	}
};

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

char str[53][53];
int chk[53][53];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%s", str[i]);
		for (int j = 0; j < n; j++)chk[i][j] = -1;
	}

	priority_queue <ele> q;
	q.emplace(0, 0, 0);

	while (!q.empty()){
		ele pp = q.top(); q.pop();

		if (chk[pp.r][pp.c] >= 0)continue;

		chk[pp.r][pp.c] = pp.m;

		for (int i = 0; i < 4; i++){
			ele psh = ele(pp.r + dr[i], pp.c + dc[i], pp.m);
			if (psh.r < 0 || psh.r >= n || psh.c < 0 || psh.c >= n)continue;
			if (chk[psh.r][psh.c] >= 0)continue;
			if (str[psh.r][psh.c] == '0')psh.m++;
			q.emplace(psh);
		}
	}

	printf("%d\n", chk[n - 1][n - 1]);
}