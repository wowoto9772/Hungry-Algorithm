//#include <stdio.h>
//#include <string>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//string wrd[103];
//string rwd[103];
//int s[103];
//
//int dp[103][16][2]; // length, remain, reverse
//int n, k;
//
//int dy(int len, int rem, int rev){
//	if (dp[len][rem][rev] != -1)return dp[len][rem][rev];
//
//	dp[len][rem][rev] = 0;
//	if (len){
//
//	}
//	for (int i = 1; i <= n; i++){
//		if (len + s[i] <= k){
//
//		}
//	}
//
//	return dp[len][rem][rev];
//}
//
//int main(){
//	scanf("%d %d", &n, &k);
//
//	for (int i = 1; i <= n; i++){
//		cin >> wrd[i];
//		rwd[i] = wrd[i];
//		s[i] = wrd[i].size();
//		reverse(rwd[i].begin(), rwd[i].end());
//	}
//}

//#include <stdio.h>
//#include <string>
//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <memory.h>
//
//using namespace std;
//
//string wrd[2][103];
//int s[103];
//
//int n, k;
//
//map <int, map<string, map<int, int> > > dp;
//
//const int mod = 835454957;
//
//int dy(int len, string rem, int rev){
//	if (dp[len][rem].count(rev) != 0)return dp[len][rem][rev];
//
//	dp[len][rem][rev] = 0;
//	if (len){
//		int s = rem.size();
//		bool flag = false;
//		for (int i = 0; !flag && i < s / 2; i++){
//			if (rem[i] != rem[s - 1 - i])flag = true;
//		}
//		if (!flag)dp[len][rem][rev] = 1;
//	}
//
//	for (int i = 1; i <= n; i++){
//		if (len + s[i] <= k){
//			int p = 0;
//			for (int j = 0; j < rem.size() && j < wrd[rev][i].size(); j++){
//				if (rem[j] == wrd[rev][i][j])p++;
//				else{
//					break;
//				}
//			}
//			if (wrd[rev][i].size() != p && p != rem.size())continue;
//			string tmp;
//			if (p < rem.size()){
//				tmp = rem.substr(p);
//				dp[len][rem][rev] += dy(len + s[i], tmp, rev);
//			}
//			else{
//				tmp = wrd[rev][i].substr(p);
//				dp[len][rem][rev] += dy(len + s[i], tmp, rev ^ 1);
//			}
//			dp[len][rem][rev] %= mod;
//		}
//	}
//
//	return dp[len][rem][rev];
//}
//
//int dp2[103][53];
//int partner[103];
//int dy2(int len, int last){
//	if (dp2[len][last] != -1)return dp2[len][last];
//
//	dp2[len][last] = n;
//	if (!len)dp2[len][last] = 0;
//
//	for (int i = 1; i <= n; i++){
//		if (partner[i]){
//			if (len + s[i] * 2 <= k){
//				dp2[len][last] += dy2(len + s[i] * 2, i);
//			}
//		}
//	}
//
//	return dp2[len][last];
//}
//
//int main(){
//	scanf("%d %d", &n, &k);
//
//	for (int i = 1; i <= n; i++){
//		cin >> wrd[0][i];
//		wrd[1][i] = wrd[0][i];
//		s[i] = wrd[0][i].size();
//		reverse(wrd[1][i].begin(), wrd[1][i].end());
//	}
//
//	int tot = dy(0, "", 0); // total
//
//	memset(dp2, 0xff, sizeof(dp2));
//	bool flag = false;
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++){
//			if (wrd[0][i] == wrd[1][j]){
//				partner[i] = j;
//				if (i != j)flag = true;
//				break;
//			}
//		}
//	}
//	int min = dy2(0, 0); // total
//	if (!flag)min = 0;
//	// - аб ©Л ╢К д╙
//	// 1 1
//	// 1 2 2 1
//	// 1 2 2 2 2 1
//
//	printf("%d\n", (tot - min + mod) % mod);
//}

#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <memory.h>

using namespace std;

string wrd[2][103];
int s[103];

int n, k;

map <int, map<string, map<int, int> > > dp;

const int mod = 835454957;

int dy(int len, string rem, int rev){
	if (dp[len][rem].count(rev) != 0)return dp[len][rem][rev];

	dp[len][rem][rev] = 0;
	if (len){
		int s = rem.size();
		bool flag = false;
		for (int i = 0; !flag && i < s / 2; i++){
			if (rem[i] != rem[s - 1 - i])flag = true;
		}
		if (!flag)dp[len][rem][rev] = 1;
	}

	for (int i = 1; i <= n; i++){
		if (len + s[i] <= k){
			int p = 0;
			for (int j = 0; j < rem.size() && j < wrd[rev][i].size(); j++){
				if (rem[j] == wrd[rev][i][j])p++;
				else{
					break;
				}
			}
			if (wrd[rev][i].size() != p && p != rem.size())continue;
			string tmp;
			if (p < rem.size()){
				tmp = rem.substr(p);
				dp[len][rem][rev] += dy(len + s[i], tmp, rev);
			}
			else{
				tmp = wrd[rev][i].substr(p);
				dp[len][rem][rev] += dy(len + s[i], tmp, rev ^ 1);
			}
			dp[len][rem][rev] %= mod;
		}
	}

	return dp[len][rem][rev];
}

int dp2[103][53];
int partner[103];
int dy2(int len, int last){
	if (dp2[len][last] != -1)return dp2[len][last];

	dp2[len][last] = n;
	if (!len)dp2[len][last] = 0;

	for (int i = 1; i <= n; i++){
		if (partner[i]){
			if (len + s[i] * 2 <= k){
				dp2[len][last] += dy2(len + s[i] * 2, i);
			}
		}
	}

	return dp2[len][last];
}

int main(){
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++){
		cin >> wrd[0][i];
		wrd[1][i] = wrd[0][i];
		s[i] = wrd[0][i].size();
		reverse(wrd[1][i].begin(), wrd[1][i].end());
	}

	int tot = dy(0, "", 0); // total

	printf("%d\n", tot);
}