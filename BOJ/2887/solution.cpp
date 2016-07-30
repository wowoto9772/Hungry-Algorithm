#include <stdio.h>
#include <algorithm>
#define ll long long

using namespace std;

int p[100003];

class Edge{
public:
	int a, b, c;
	Edge(){}
	Edge(int x, int y, int z){ a = x, b = y, c = z; }
	bool operator<(const Edge &A)const{
		return c < A.c;
	}
}edge[600003];

class Dat{
public:
	int i, v;
	Dat(){}
	Dat(int a, int b){ i = a, v = b; }

	bool operator<(const Dat &A)const{
		return v < A.v;
	}
}raw[100003];

int x[100003], y[100003], z[100003];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
	}

	int top = 0;
	for (int i = 1; i <= n; i++)raw[i - 1] = Dat(i, x[i]);
	sort(raw, raw + n);
	for (int i = 1; i < n; i++)edge[top++] = Edge(raw[i].i, raw[i - 1].i, abs(raw[i].v - raw[i - 1].v));

	for (int i = 1; i <= n; i++)raw[i - 1] = Dat(i, y[i]);
	sort(raw, raw + n);
	for (int i = 1; i < n; i++)edge[top++] = Edge(raw[i].i, raw[i - 1].i, abs(raw[i].v - raw[i - 1].v));

	for (int i = 1; i <= n; i++)raw[i - 1] = Dat(i, z[i]);
	sort(raw, raw + n);
	for (int i = 1; i < n; i++)edge[top++] = Edge(raw[i].i, raw[i - 1].i, abs(raw[i].v - raw[i - 1].v));

	sort(edge, edge + top);

	int c = 0;
	ll ans = 0;
	for (int i = 0; i < top && c < n-1; i++){
		int a = edge[i].a, b = edge[i].b;
		while (p[a])a = p[a];
		while (p[b])b = p[b];
		int pa = a, pb = b;

		a = edge[i].a, b = edge[i].b;
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

		if (pa == pb)continue;
		else{
			p[a] = b;
			ans += edge[i].c;
			c++;
		}
	}

	printf("%lld\n", ans);
}