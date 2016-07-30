#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;


int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n){
		int max = 0;
		string str, s;

		vector < vector <string> > S;
		S.resize(n + 1);

		int c = 0;

		string g[103];
		int top = 0;
		int ans = 0;

		for (int i = 1; i <= n; i++){
			cin >> str;
			int len = str.size();
			for (int j = 0; j < len; j++){
				if (str[j] == '.')continue;
				if (str[j] == ':'){
					g[top++] = s;
					s = "";
					continue;
				}
				if (str[j] == ','){
					S[top - 1].push_back(s);
					s = "";
				}
				else{
					s += str[j];
				}
			}
			if (s != ""){
				S[top - 1].push_back(s);
				s = "";
			}
		}

		queue <string> q;
		map <string, bool> chk;
		for (int i = 0; i < S[0].size(); i++){
			q.push(S[0][i]);
			chk[S[0][i]] = true;
		}

		while (!q.empty()){
			string f = q.front(); q.pop();

			bool flag = false;
			int x = -1;
			for (int i = 0; i < top; i++){
				if (f == g[i]){
					flag = true;
					x = i;
					break;
				}
			}

			if (flag){
				for (int i = 0; i < S[x].size(); i++){
					if (chk[S[x][i]] != 0)continue;
					chk[S[x][i]] = true;
					q.push(S[x][i]);
				}
			}
			else{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}
