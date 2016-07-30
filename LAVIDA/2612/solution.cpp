#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;

int dp[10003];
int ds[10003];
int I[10003];
vector < int > L[10003];

int parent[10003];
int min(int a, int b){ return a < b ? a : b; }

void swp(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
int k;
int dy(int c){
	if (dp[c] != -1)return dp[c];

	dp[c] = I[c];
	ds[c] = c;

	int s = L[c].size();
	for (int i = 0; i < s; i++){
		int n = L[c][i];
		if (dp[n] != -1)continue;
		if (dp[c] < I[c] + dy(n)){
			parent[n] = c;
			dp[c] = I[c] + dp[n];
			ds[c] = ds[n];
		}
		else if (dp[c] == I[c] + dy(n)){
			ds[c] = min(ds[c], ds[n]);
		}
	}

	return dp[c];
}

int main(){
	int v;
	while (scanf("%d", &v) == 1 && v){

		int in[10003] = { 0 };
		for (int i = 1; i <= v; i++){
			scanf("%d", &I[i]);
			L[i].clear();
		}

		for (int i = 1; i < v; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			in[a]++;
			in[b]++;

			L[a].push_back(b);
			L[b].push_back(a);
		}

		if (v == 1){
			printf("%d %d\n", I[1], 1);
			continue;
		}

		memset(dp, 0xff, sizeof(dp));
		int ans = 0, anx = v+1;

		int root = -1;
		for (int i = 1; i <= v; i++){
			if (in[i] == 1){
				if (root == -1)root = i;
				dy(i);
				ans = dp[i];
				anx = min(i, ds[i]);
				break;
			}
		}
		for (int i = 1; i <= v; i++){
			if (ans < dy(i)){
				ans = dy(i);
				anx = min(anx, min(i, ds[i]));
			}
			else if (ans == dy(i)){
				anx = min(anx, min(i, ds[i]));
			}
		}

		for (int i = 1; i <= v; i++){
			int t = 0;
			int max[2] = { 0 };
			int s[2] = { v+1, v+1 };
			int c = i;
			for (int j = 0; j < L[c].size(); j++){
				int n = L[c][j];
				if (n == parent[c])continue;
				if (t < 2){
					s[t] = ds[n];
					max[t++] = dp[n];
				}
				else{
					if (max[0] > max[1]){
						swp(&max[0], &max[1]);
						swp(&s[0], &s[1]);
					}
					if (max[0] < dp[n]){
						max[0] = dp[n];
						s[0] = ds[n];
					}
				}
			}
			int cmp = max[0] + max[1] + I[c];
			if (dp[c] <= cmp && t == 2){
				if (ans < cmp){
					ans = cmp;
					anx = min(s[0], s[1]);
				}
				else if (ans == cmp){
					anx = min(anx, min(s[0], s[1]));
				}
			}
		}

		printf("%d %d\n", ans, anx);
	}
}