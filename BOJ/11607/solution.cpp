#include <stdio.h>
#include <queue>

using namespace std;

char str[505][505];
bool chk[505][505];

class ele{
public:
	int r, c, m;
	ele(){}
	ele(int r_, int c_, int m_){
		r = r_, c = c_, m = m_;
	}
	bool operator<(const ele &A)const{
		return m > A.m;
	}
};

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main(){

	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)scanf("%s", str[i]);

	priority_queue < ele > q;

	q.emplace(0, 0, 0);

	while (!q.empty()){

		ele pp = q.top(); q.pop();

		if (pp.r == r - 1 && pp.c == c - 1){
			printf("%d\n", pp.m);
			return 0;
		}

		if (chk[pp.r][pp.c])continue;

		chk[pp.r][pp.c] = true;

		int k = str[pp.r][pp.c] - '0';

		for (int i = 0; i < 4; i++){

			ele psh = ele(pp.r + dr[i] * k, pp.c + dc[i] * k, pp.m + 1);

			if (psh.r < 0 || psh.r >= r || psh.c < 0 || psh.c >= c)continue;
			if (chk[psh.r][psh.c])continue;

			q.emplace(psh);

		}

	}

	printf("IMPOSSIBLE\n");

}