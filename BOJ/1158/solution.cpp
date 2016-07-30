#include <stdio.h>
#include <iostream>
using namespace std;

int ans[5001];
bool chk[5001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int cnt = 0, top = 1;
	while (top != n + 1) {
		int selected = 0;

		for (int i = 1; selected != m; i++) {
			cnt++;
			if (cnt > n)cnt -= n;
			if (chk[cnt])continue;
			else
				selected++;
		}

		chk[cnt] = true;
		ans[top] = cnt;
		top++;
	}

	printf("<");
	for (int i = 1; i <= n - 1; i++)printf("%d, ", ans[i]);
	printf("%d>\n", ans[n]);
}