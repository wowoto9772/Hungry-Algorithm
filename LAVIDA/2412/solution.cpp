#include <stdio.h>
#include <string.h>
#include <memory.h>

char str[103][103];
int L[103];
int spc[103]['Z' + 5];
int s[103];
bool iflag;
int n, g;
void func(int cur, int flag){
	if (cur == g){
		iflag = true;
		return;
	}
	if (s[cur] < L[flag] && spc[cur][str[flag][s[cur]]])func(cur + 1, flag);
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d", &n, &g);

		for (int i = 0; i < n; i++){
			scanf("%s", str[i]);
			L[i] = strlen(str[i]);
		}

		memset(spc, 0, sizeof(spc));
		for (int i = 0; i < g; i++){
			scanf("%d", &s[i]);
			s[i] -= 1;
			char st[103] = { 0 };
			scanf("%s", st);
			int l = strlen(st);

			for (int j = 0; j < l; j++){
				spc[i][st[j]] = 1;
			}
		}

		int x = 0;
		char ans[103] = { 0 };

		for (int i = 0; i < n; i++){
			iflag = false;
			func(0, i);
			if (iflag){
				x++;
				strcpy(ans, str[i]);
				if (x == 2)break;
			}
		}

		if (x > 1)printf("YOU KNOW NOTHING\n");
		else if (x < 1)printf("DEAD DRUNK\n");
		else
			printf("%s\n", ans);
	}
}
