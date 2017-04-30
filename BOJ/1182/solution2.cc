#include <stdio.h>

int Num[20];
int cnt;
int N;

void solve(int cur, int sum)
{
    if(cur >= N)return ;
	solve(cur+1, sum+Num[cur]); // 선택.
    if(sum+Num[cur] == S)cnt++; // 선택 했을 때만 경우의 수에 더한다.
    solve(cur+1, sum); // 선택하지 않는다.
    return ;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	int i;

	scanf("%d%d", &N, &S);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &Num[i]);
	}

	solve(0, 0);
	printf("%d\n", cnt);

	return 0;
}