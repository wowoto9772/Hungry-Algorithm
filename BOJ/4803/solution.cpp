#include <stdio.h>

int p[505];

int main(){
	int n, m;
	int tc = 0;
	while (scanf("%d %d", &n, &m) == 2){
		if (!n && !m)break;

		for (int i = 1; i <= n; i++)p[i] = 0;

		bool flag[505] = { 0 };

		for (int i = 1; i <= m; i++){
			int a, b;
			scanf("%d %d", &a, &b);

			while (p[a])a = p[a];
			while (p[b])b = p[b];

			if (a == b){
				flag[a] = true;
			}
			else{
				if(!flag[b])flag[b] = flag[a];
				p[a] = b;
			}
		}

		int t = 0;
		for (int i = 1; i <= n; i++){
			if (!p[i] && !flag[i])t++;
		}

		printf("Case %d: ", ++tc);
		if (t > 1){
			printf("A forest of %d trees.\n", t);
		}
		else if (t == 1){
			printf("There is one tree.\n");
		}
		else{
			printf("No trees.\n");
		}
	}
}