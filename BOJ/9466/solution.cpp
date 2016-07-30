#include <stdio.h>
#include <memory.h>

#define MAXV 100003

int node[MAXV * 2];
bool cyc[MAXV];
int nxt[MAXV];
int mapp[MAXV];
int vst[MAXV];
int top;

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		int n;
		scanf("%d", &n);

		int ans = 0;
		for (int i = 1; i <= n; i++){
			cyc[i] = false;
			scanf("%d", &nxt[i]);
		}

		int prev = top;

		for (int i = 1; i <= n; i++){

			if (cyc[i])continue;
			int c = i;
			top++;

			int stk = 0;

			vst[c] = top;
			node[stk] = c;
			mapp[c] = stk++;

			while (c = nxt[c]){
				if (cyc[c])break;
				else if (vst[c] != top){
					if (vst[c] > prev)break;
					vst[c] = top;
					node[stk] = c;
					mapp[c] = stk++;
				}
				else{
					// cycle 
					for (int j = mapp[c]; j < stk; j++)cyc[node[j]] = true;
					ans += stk - mapp[c];
					break;
				}
			}
		}

		printf("%d\n", n - ans);

	}

}

// 5 2 5 2 2 2 : RTE