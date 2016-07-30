#include <stdio.h>
#include <algorithm>

using namespace std;

int p[100003];
int e[100003];

int find(int u){
	if (p[u] == -1)return u;
	return p[u] = find(p[u]);
}

int merge(int u, int v){
	if (u == -1 || v == -1)return max(u, v);

	u = find(u), v = find(v);
	if (u == v)return v;

	p[u] = v;

	return v;
}

bool isEnemy(int u, int v){

	u = find(u), v = find(v);

	if (u == v)return false; // not enemy

	int a = merge(u, e[v]), b = merge(v, e[u]);

	e[a] = b;
	e[b] = a;

	return true;
}

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)e[i] = p[i] = -1;

	int ans = 0;

	for (int i = 1; i <= m; i++){

		int a, b;
		scanf("%d %d", &a, &b);

		if (ans)continue;

		if (!isEnemy(a, b))ans = i;

	}

	printf("%d\n", ans);
}