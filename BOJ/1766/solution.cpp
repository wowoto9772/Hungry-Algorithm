#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int in[32003];
bool chk[32003];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	vector < vector <int> > pst;
	pst.resize(n + 1);

	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		in[b]++;
		pst[a].push_back(b);
	}

	priority_queue <int> q;
	for (int i = 1; i <= n; i++){
		if (!in[i]){
			q.push(-i);
			chk[i] = true;
		}
	}

	while (!q.empty()){
		int f = -q.top(); q.pop();
		printf("%d ", f);
		for (int i = 0; i < pst[f].size(); i++){
			int nxt = pst[f][i];
			in[nxt]--;
			if (!in[nxt]){
				q.push(-nxt);
				chk[nxt] = true;
			}
		}
	}


}