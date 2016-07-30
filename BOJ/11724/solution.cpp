#include <stdio.h>

int p[1003];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		int ca = a, cb = b;

		while (p[a])a = p[a];
		while (p[b])b = p[b];

		int pa = a, pb = b;

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
		if (a != b)p[a] = b;
	}

	int c = 0;
	for (int i = 1; i <= n; i++)if (!p[i])c++;

	printf("%d\n", c);
}