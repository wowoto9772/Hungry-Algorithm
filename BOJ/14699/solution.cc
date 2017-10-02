#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector < vector <int> > lnk;
int h[5003], dp[5003];

int dy(int c){
	int &ret = dp[c];
	if (ret != -1)return ret;
	ret = 0;
	for (auto &e : lnk[c]){
		if (h[c] < h[e]){
			ret = max(1 + dy(e), ret);
		}
	}
	return ret;
}

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		scanf("%d", &h[i]);
		dp[i] = -1;
	}

	lnk.resize(n + 1);

	while (m--){
		int a, b;
		scanf("%d %d", &a, &b);
		lnk[a].push_back(b);
		lnk[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)printf("%d\n", 1 + dy(i));

}