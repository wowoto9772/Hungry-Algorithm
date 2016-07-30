#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, map<int, map<int, int> > > dp;
vector <string> wrd[2]; // 0 : word, 1 : toggle word
int N, L;

int dy(string rem, int clen, int rev){
	if (dp[rem][clen].count(rev) != 0)return dp[rem][clen][rev];

	if (clen == L){
		for (int i = 0; i<rem.size() / 2; i++){
			if (rem[i] != rem[rem.size() - 1 - i])return dp[rem][clen][rev] = 0;
		}
		return dp[rem][clen][rev] = 1;
	}

	dp[rem][clen][rev] = 0;

	for (int i = 0; i<N; i++){
		int nlen = clen + wrd[0][i].size();
		if (nlen > L)continue;

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
			dp[rem][clen][rev] += dy(tmp, nlen, rev);
		}
		else{
			tmp = wrd[rev][i].substr(p);
			dp[rem][clen][rev] += dy(tmp, nlen, rev ^ 1);
		}
	}

	return dp[rem][clen][rev];
}

int main(){
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= N; i++){
		string j;
		cin >> j;
		wrd[0].push_back(j);
		reverse(j.begin(), j.end());
		wrd[1].push_back(j);
	}

	printf("%d\n", dy("", 0, 0));
}