#include <stdio.h>
#include <memory.h>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 2^16 * 16

int dp[16][1 << 16];

char str[103];
int f[16], e[16], s[16];
int n;

int dy(int c, int S){

	if (dp[c][S] != -1)return dp[c][S];

	dp[c][S] = 0;

	for (int i = 0; i < n; i++){
		if (S & (1 << i))continue; // used
		if (e[c] == f[i]){
			dp[c][S] = max(dp[c][S], dy(i, S | (1 << i)) + s[i]);
		}
	}

	return dp[c][S];

}

int main(){

	scanf("%d", &n);

	vector <string> name;

	for (int i = 0; i < n; i++){
		scanf("%s", str);

		name.push_back(string(str));
	}

	n = 0;
	for (auto &i : name){
		f[n] = i[0];
		e[n] = i.back();
		s[n] = i.size();
		n++;
	}

	memset(dp, 0xff, sizeof(dp));

	int ans = 0;
	for (int i = 0; i < n; i++){
		ans = max(ans, dy(i, (1 << i)) + s[i]);
	}

	printf("%d\n", ans);

}