#include <stdio.h>
#include <vector>
#include <queue>

#define max(a, b) (a<b?b:a)

using namespace std;

int p[1000003];
bool chk[1000003];

int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){
		vector < vector<int> > LR, RL;
		LR.resize(n), RL.resize(n);
		for (int i = 0; i < n; i++){
			scanf("%d", &p[i]);
			if (i + p[i] < n){
				LR[i + p[i]].push_back(i);
			}
			if (i - p[i] >= 0){
				RL[i - p[i]].push_back(i);
			}
			chk[i] = false;
		}

		queue <int> q;
		q.push(0);
		
		int ans = 0;
		while (!q.empty()){
			int c = q.front(); q.pop();

			ans = max(ans, c);
		
			int nc = c + p[c];
			if (nc < n){ // go L to R
				for (int i = 0; i < RL[nc].size(); i++){
					if (chk[RL[nc][i]])continue;
					else{
						chk[RL[nc][i]] = true;
						q.push(RL[nc][i]);
					}
				}
			}

			nc = c - p[c];

			if (nc >= 0){ // go R to L
				for (int i = 0; i < LR[nc].size(); i++){
					if (chk[LR[nc][i]])continue;
					else{
						chk[LR[nc][i]] = true;
						q.push(LR[nc][i]);
					}
				}
			}
		}

		printf("%d\n", ans);
	}
}