#include <stdio.h>

int p[50003];

int main(){
	int n, m, T = 0;
	while (scanf("%d %d", &n, &m) == 2){
		if (!n && !m)break;
		for (int i = 1; i <= n; i++)p[i] = 0;
		for (int i = 0; i < m; i++){
			int a, b;
			scanf("%d %d", &a, &b);

			int ca = a, cb = b;

			while (p[a])a = p[a];
			while (p[b])b = p[b];
			int pa = a, pb = b;
			if (pa == pb)continue;
			else{
				a = ca, b = cb;
				while (p[a]){
					int t = p[a];
					p[a] = pa;
					a = t;
				}
				while (p[b]){
					int t = p[b];
					p[b] = pb;
					b = t;
				}
				p[a] = b;
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)if (!p[i])ans++;

		printf("Case %d: %d\n", ++T, ans);
	}
}