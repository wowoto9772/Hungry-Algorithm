#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int p[100003];

int main(){
	int n;
	scanf("%d", &n);

	vector < vector <int> > lnk;
	lnk.resize(n + 1);

	for (int i = 1; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		lnk[a].push_back(b);
		lnk[b].push_back(a);
	}

	queue <int> q;
	q.push(1);

	while (!q.empty()){
		int f = q.front(); q.pop();

		for (int i = 0; i < lnk[f].size(); i++){
			if (!p[lnk[f][i]]){
				p[lnk[f][i]] = f;
				q.push(lnk[f][i]);
			}
		}
	}

	for (int i = 2; i <= n; i++)printf("%d\n", p[i]);
}