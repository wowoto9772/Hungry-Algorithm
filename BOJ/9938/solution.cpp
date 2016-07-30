#include <stdio.h>

int p[300003]; // parent
bool c[300003]; // charged

int find(int u){
	if (p[u] == u)return u;
	return p[u] = find(p[u]);
}

void unite(int u, int v){
	p[find(u)] = find(v);
}

int main(){

	int m, n;
	scanf("%d %d ", &m, &n);

	for (int i = 1; i <= n; i++)p[i] = i;

	for (int i = 1; i <= m; i++){

		int a, b;
		scanf("%d %d", &a, &b);

		if (!c[a]){
			c[a] = true;
			unite(find(a), find(b));
		}
		else if (!c[b]){
			c[b] = true;
			unite(find(b), find(a));
		}
		else if (!c[find(a)]){
			c[find(a)] = true;
			unite(find(a), find(b));
		}
		else if (!c[find(b)]){
			c[find(b)] = true;
			unite(find(b), find(a));
		}
		else{
			printf("SMECE\n");
			continue;
		}

		printf("LADICA\n");

	}
}