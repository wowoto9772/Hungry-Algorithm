#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int dp[1003][1003][3];
int e[1003][1003];

int dy(int i, int j, int r){

	int &ret = dp[i][j][r];
	if (ret != -1)return ret;
	ret = 0;
	if (i + 1 < n){
		if (e[i + 1][j] == r)ret = max(ret, 1 + dy(i + 1, j, (r + 1) % 3));
		else
			ret = max(ret, dy(i + 1, j, r));
	}
	if (j + 1 < n){
		if (e[i][j + 1] == r)ret = max(ret, 1 + dy(i, j + 1, (r + 1) % 3));
		else
			ret = max(ret, dy(i, j + 1, r));
	}
	return ret;

}

int main(){

	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &e[i][j]);
			for (int k = 0; k < 3; k++)dp[i][j][k] = -1;
		}
	}

	int ans = 0;
	if (e[0][0] == 0)ans = 1 + dy(0, 0, 1);
	else
		ans = dy(0, 0, 0);
	printf("%d\n", ans);

}