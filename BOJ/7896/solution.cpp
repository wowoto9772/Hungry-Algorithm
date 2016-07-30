#include <stdio.h>
#include <vector>

using namespace std;

vector < vector <int> > lnk;
vector < vector <int> > rnk;

bool vst[202];
int dfn[202];
int grp[202];
int top;

void dfs(int a){
	if (vst[a])return;
	vst[a] = true;
	for (int i = 0; i < lnk[a].size(); i++){
		dfs(lnk[a][i]);
	}
	dfn[top++] = a;
}

int gcnt;
void rfs(int a){
	if (grp[a])return;
	grp[a] = gcnt;

	for (int i = 0; i < rnk[a].size(); i++){
		rfs(rnk[a][i]);
	}
}

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		int n, m;
		scanf("%d %d", &n, &m);

		lnk.resize(n + 1), rnk.resize(n + 1);

		for (int i = 1; i <= n; i++)dfn[i] = 0, vst[i] = false;

		for (int i = 1; i <= m; i++){
			int a, b, k;
			scanf("%d %d %d", &a, &b, &k);
			
			lnk[a].push_back(b);
			rnk[b].push_back(a);
			
			if (k){ // two-way
				lnk[b].push_back(a);
				rnk[a].push_back(b);
			}
		}

		top = 0;
		for (int i = 1; i <= n; i++)dfs(i);

		gcnt = 0;
		for (int i = top - 1; i >= 0; i--){
			if (!grp[dfn[i]]){
				gcnt++;
				rfs(dfn[i]);

				if (gcnt > 1)break;
			}
		}

		lnk.clear();
		rnk.clear();

		if (gcnt == 1)printf("possible\n");
		else
			printf("impossible\n");

	}

} // 문제 잘못 이해 : 모든 엣지를 한번 씩 통과하고, 시작점과 끝점이 같아져야 함.

#include <stdio.h>

int in[202];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){

		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++)in[i] = 0;

		for (int i = 1; i <= m; i++){
			int a, b, k;
			scanf("%d %d %d", &a, &b, &k);

			if (k){
				in[b]++;
			}
			else{
				in[a]++;
				in[b]++;
			}
		}

		int c = 0;
		for (int i = 1; i <= n; i++){
			if (in[i] % 2)c++;
		}

		if (c != 0 && c != 2){
			printf("im");
		}
		printf("possible\n");
	}
}