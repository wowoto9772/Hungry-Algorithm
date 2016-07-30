#include <stdio.h>

bool L[103][103]; 
bool v[103];
int d[103], dt = 0;

bool R[103][103]; 
int g[103], gt = 0;

int n, c;

void dfn(int a){
	v[a] = true;
	for (int j = 1; j <= n; j++){
		if (!v[j] && L[a][j]){
			dfn(j);
		}
	}
	d[++dt] = a;
}

void cyc(int a){
	g[a] = gt; // same group
	c++;
	for (int j = 1; j <= n; j++){
		if (!g[j] && R[a][j]){
			cyc(j);
		}
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		int a, b;
		scanf("%d", &a);
		for (int j = 1; j <= a; j++){
			scanf("%d", &b);
			L[i][b] = true; // forward
			R[b][i] = true; // reverse
		}
	}

	for (int i = 1; i <= n; i++){
		if (!v[i]){
			dfn(i);
		}
	}

	bool f = false;

	for (int i = dt; !f && i >= 1; i--){
		if (!g[d[i]]){
			++gt;
			c = 0;
			cyc(d[i]);
			if (c > 1)f = true;
		}
	}

	if (!f)printf("Yes\n");
	else
		printf("No\n");
}