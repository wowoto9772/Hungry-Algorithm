#include <stdio.h>
#include <string.h>

#include <string>

using namespace std;

string dp[1003];

string wrd[10004];

string tar;

int n, m;

bool possible(string a, string b){

	if(a[0] != b[0] || a.back() != b.back())return false;

	int c['z'+3] = {0};

	int l = a.size();

	for(int i=0; i<l; i++){
		c[a[i]]++;
		c[b[i]]--;
	}

	for(int i='a'; i<='z'; i++)if(c[i])return false;

	return true;

}

int not_space(string a){

	int r = 0;
	int l = a.size();

	for(int i=0; i<l; i++){
		if(a[i] != ' ')r++;
	}

	return r;

}

bool amb = false;

string dy(int c){
	
	if(c == m)return "";
	if(dp[c] != "")return dp[c];

	for(int i=1; i<=n && !amb; i++){
		
		int s = wrd[i].size();

		if(c + s <= m){

			if(possible(wrd[i], tar.substr(c, s))){

				if(dp[c] == "")dp[c] = wrd[i] + " " + dy(c + s);
				else{
					
					string tmp = wrd[i] + " " + dy(c + s);

					if(not_space(tmp) == m-c){
						if(not_space(dp[c]) == m-c){
							amb = true;
						}else{
							dp[c] = tmp;
						}
					}

				}

			}

		}

	}


	return dp[c];

}


char str[1003];

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		scanf("%s", str);

		tar = string(str);

		m = tar.size();

		scanf("%d", &n);

		for(int i=1; i<=n; i++){
			scanf("%s", str);
			wrd[i] = string(str);
		}

		for(int i=0; i<m; i++)dp[i] = "";

		amb = false;

		string sexy = dy(0);

		if(amb)printf("ambiguous\n");
		else{
			if(not_space(dp[0]) == m)printf("%s\n", dp[0].substr(0, dp[0].size()-1).c_str());
			else{
				printf("impossible\n");
			}
		}

	}

}
