#include <stdio.h>

#include <vector>

#include <queue>

using namespace std;

int r[200003];
int d[200003];
int o[200003];

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	vector < vector < int > > lnk;

	lnk.resize(n+m+1);

	for(int i=1; i<=m; i++){
		
		int x, y;
		scanf("%d %d", &x, &y);

		for(int j=x; j<=n; j+=y){
			lnk[j].push_back(n+i);
			lnk[n+i].push_back(j);
		}

	}

	int s, a;
	scanf("%d %d", &s, &a);

	for(int i=1; i<=n+m; i++)d[i] = -2;
	
	queue <int> q;

	d[s] = 0;
	q.push(s);

	while(!q.empty() && d[a] == -2){
		
		int f = q.front(); q.pop();

		for(int i=0; i<lnk[f].size(); i++){
			
			int g = lnk[f][i];

			if(d[g] == -2){
				d[g] = d[f] + 1;
				r[g] = f;
				q.push(g);
			}
			
		}

	}

	printf("%d\n", d[a]>>1);

	if(d[a] > 0){
		
		int c = r[a];
		int top = 0;

		while(c > 0){
			o[top++] = c - n;
			c = r[r[c]];
		}

		for(int i=top-1; i>=0; i--)printf("%d\n", o[i]);

	}

}
