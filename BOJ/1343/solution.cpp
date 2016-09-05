#include <stdio.h>

#include <string>

using namespace std;

string dp[503];

string str;
char _str[503];

int s;

bool valid(string c){
	
	for(int i=0; i<c.size(); i++){
		if(c[i] == 'C')return false;
	}

	return true;

}

string dy(int c){
	
	if(c == s)return "";
	if(dp[c] != "")return dp[c];

	dp[c] = "CANT";

	if(str[c] == '.')dp[c] = str[c] + dy(c+1);
	else{
		if(c+4 <= s){
			if(str.substr(c, 4) == "XXXX"){
				dp[c] = "AAAA" + dy(c+4);
				if(dp[c].size() == s-c && valid(dp[c]))return dp[c];
				else
					dp[c] = "CANT";
			}
		}
		if(c+2 <= s){
			if(str.substr(c, 2) == "XX"){
				dp[c] = "BB" + dy(c+2);
				if(dp[c].size() == s-c && valid(dp[c]))return dp[c];
				else
					dp[c] = "CANT";
			}
		}
	}

	return dp[c];

}

int main(){

	scanf("%s", _str);

	str = string(_str);

	s = str.size();

	string out = dy(0);

	if(out.size() == s && valid(out))printf("%s", out.c_str());
	else
		printf("-1");

}
