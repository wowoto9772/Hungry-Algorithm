#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

string str;

map <string, bool> dp;

bool dy(string c){
	if (c == ""){
		return 1;
	}
	else if (dp.count(c) != 0)return dp[c];

	dp[c] = false;

	int s = c.size();

	int x, y;
	for (int i = 0; i < s; i++){
		x = i;
		y = x;
		for (int j = i + 1; j < s; j++){
			if (c[i] == c[j]){
				y = j;
				i = j;
			}
			else
				break;
		}

		if (x < y){
			string nstr = c.substr(0, x) + c.substr(y+1);
			dp[c] = dy(nstr);
			if (dp[c])return dp[c];
		}
	}

	return dp[c];
}

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		cin >> str;

		int s = str.size();

		// dp.clear();

		printf("%d\n", dy(str) ? 1 : 0);
	}
}