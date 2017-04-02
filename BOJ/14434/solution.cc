#include <cstdio>
#include <vector>

using namespace std;

int h[200003];
int a[200003];
vector < vector <int> > g;

int pos(int k, int c){
	int l = 0, r = g[k].size()-1, m;
	int v = -1;
	while(l <= r){
		m = (l+r) / 2;
		if(g[k][m] > c)r = m - 1;
		else{
			l = m + 1;
			v = m;
		}
	}
	return v;
}

int main(){
	
	int n, m, k, q;
	scanf("%d %d %d %d", &n, &m, &k, &q);
	
	for(int i=1; i<=m; i++)scanf("%d", &h[i]);
	
	g.resize(n+1);
	
	for(int i=1; i<=k; i++){
		int x;
		scanf("%d", &x);
		g[x].push_back(i);
	}
	
	for(int i=1; i<=q; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		
		int l = 1, r = k, mi;
		int v = k+1;
		
		while(l <= r){
			mi = (l+r) / 2;
			int p = pos(x, mi)+1 + pos(y, mi)+1;
			if(p >= h[z]){
				r = mi - 1;
				v = mi;
			}
			else
				l = mi + 1;
		}
		
		a[v]++;
	}
	
	int s = 0;
	for(int i=1; i<=k; i++){
		s += a[i];
		printf("%d\n", s);
	}
	
}