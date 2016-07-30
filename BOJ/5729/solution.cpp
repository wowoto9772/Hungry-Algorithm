#include <stdio.h>
#include <memory.h>

int I[10003];
bool chk[10000002];

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n){
		memset(chk, 0, sizeof(chk));
		int len = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", &I[i]);
			len += I[i];
			chk[len] = true;
		}

		int x = -1;
		for (int i = n; x == -1 && i >= 3; i--){
			if (len%i)continue;
			int cur = len / i;
			for (int j = 1; j <= cur; j++){
				bool flag = false;
				for (int k = j; !flag && k <= len; k += cur){
					if (!chk[k])flag = true;
				}
				if (!flag){
					x = n - i;
					break;
				}
			}
		}
		
		printf("%d\n", x);
	}
}

// 10
// 4 5 5 4 1 5 5 5 5 1