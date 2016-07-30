#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class PalindromePhrases{
public:
	int n;
	map <int, map<string, map <int, long long> > > chk;
	vector <string> wrd[2]; // 0 : word, 1 : toggle word
	long long dy(int cur, string rem, int flg){
		if (chk[cur][rem].count(flg) != 0)return chk[cur][rem][flg];

		chk[cur][rem][flg] = 0;

		if (cur){ // palindrome check
			int s = rem.size();
			bool flag = false;
			for (int i = 0; !flag && i < s / 2; i++){
				if (rem[i] != rem[s - 1 - i])flag = true;
			}
			if (!flag)chk[cur][rem][flg] = 1;
		}

		if (cur == (1 << n) - 1)return chk[cur][rem][flg];

		for (int i = 0; i < n; i++){
			int nxt = 1 << i;
			if ((cur & nxt) > 0)continue;

			int p = 0;
			for (int j = 0; j < rem.size() && j < wrd[flg][i].size(); j++){
				if (rem[j] == wrd[flg][i][j])p++;
				else{
					break;
				}
			}
			if (wrd[flg][i].size() != p && p != rem.size())continue;
			string tmp;
			if (p < rem.size()){
				tmp = rem.substr(p);
				chk[cur][rem][flg] += dy(cur | nxt, tmp, flg);
			}
			else{
				tmp = wrd[flg][i].substr(p);
				chk[cur][rem][flg] += dy(cur | nxt, tmp, flg ^ 1);
			}
		}

		return chk[cur][rem][flg];
	}

	long long getAmount(vector <string> words){
		n = words.size();
		wrd[0] = wrd[1] = words;
		for (int i = 0; i < wrd[1].size(); i++)reverse(wrd[1][i].begin(), wrd[1][i].end());
		return dy(0, "", 0);
	}
};

int main()
{
	int n;
	scanf("%d", &n);

	PalindromePhrases A;
	vector <string> a;
	string tmp;
	for (int i = 1; i <= n; i++){
		cin >> tmp;
		a.push_back(tmp);
	}
	printf("%lld\n", A.getAmount(a));
}
// topcoder SRM 439 Div1 Level Two