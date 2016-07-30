#include <stdio.h>

int p[1000003];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++){
		int a;
		scanf("%d", &a);

		if (a){
			
			int b;
			scanf("%d %d", &a, &b);

			while (p[a])a = p[a];
			while (p[b])b = p[b];

			if (a == b)printf("YES\n");
			else
				printf("NO\n");
		}
		else{

			int b;
			scanf("%d %d", &a, &b);

			int ca = a, cb = b;

			while (p[a])a = p[a];
			while (p[b])b = p[b];

			int pa = a, pb = b;

			while (p[ca]){
				int t = p[ca];
				p[ca] = pa;
				ca = t;
			}

			while (p[cb]){
				int t = p[cb];
				p[cb] = pb;
				cb = t;
			}

			if (pa != pb)p[pa] = pb;
		}

	}
}