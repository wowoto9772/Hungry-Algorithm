#include <stdio.h>
#include <vector>
#include <algorithm>
#define min(a, b) (a<b?a:b)

using namespace std;

int k, n;
vector < vector<int> > lnk;
bool isEnd = false;
bool used[909];

void func(vector <int> cur, int cnt){
	if (cnt == k){
		isEnd = true;
		sort(cur.begin(), cur.end());
		for (int i = 0; i < cur.size(); i++){
			printf("%d\n", cur[i]);
		}
		return;
	}
	int nxt = 909;
	for (int i = 0; i < cur.size(); i++){
		for (int j = 0; j < lnk[cur[i]].size(); j++){
			int nnxt = lnk[cur[i]][j];
			if (used[nnxt])continue;
			else{
				nxt = min(nxt, nnxt);
			}
		}
	}
	if (nxt == 909)return;
	used[nxt] = true;
	cur.push_back(nxt);
	func(cur, cnt+1);
	cur.pop_back();
	used[nxt] = false;
}

int main(){
	int m;
	scanf("%d %d %d", &k, &n, &m);

	lnk.resize(n + 1);

	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		lnk[a].push_back(b);
		lnk[b].push_back(a);
	}

	for (int i = 1; i <= n; i++){
		sort(lnk[i].begin(), lnk[i].end());
	}

	for (int i = 1; !isEnd && i <= n; i++){
		used[i] = true;
		func({ i }, 1);
		used[i] = false;
	}
}