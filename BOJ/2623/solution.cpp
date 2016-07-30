#include <stdio.h>
#include <queue>

using namespace std;

bool chk[1003][1003];
int in[1003];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++){
		int c;
		scanf("%d", &c);

		int p = 0;
		for (int j = 1; j <= c; j++){
			int a;
			scanf("%d", &a);
			if (p){
				if (!chk[p][a]){ // duplicated
					chk[p][a] = true;
					in[a]++;
				}
			}
			p = a;
		}
	}

	queue <int> q;
	bool used[1003] = { 0 };
	for (int i = 1; i <= n; i++){
		if (in[i])continue;
		q.push(i);
		used[i] = true;
	}

	vector <int> x;

	while (!q.empty()){
		int f = q.front(); q.pop();
		x.push_back(f);
		for (int j = 1; j <= n; j++){
			if (!used[j] && chk[f][j]){
				in[j]--;
				if (!in[j]){
					q.push(j);
					used[j] = true;
				}
			}
		}
	}

	if (x.size() < n){
		printf("0\n");
	}
	else{
		for (int i = 0; i < x.size(); i++)printf("%d\n", x[i]);
	}
}