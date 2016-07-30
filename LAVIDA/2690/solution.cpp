#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

char str[35][22 * 32];

int main(){
	int n;
	scanf("%d", &n);

	map <string, int> pars;
	map <int, string> conv;

	int top = 0;
	vector < vector <int> > lnkage;
	lnkage.resize(33);

	for (int i = 1; i <= n; i++){
		while (strcmp(str[i], "") == 0)gets(str[i]);
		int s = strlen(str[i]);

		string node;
		int beg = 0, lnk = 0;
		for (int j = 0; j < s; j++){
			if (str[i][j] == ' '){
				if (pars[node]){
					lnk = pars[node];
				}
				else{
					pars[node] = ++top;
					lnk = pars[node];
					conv[lnk] = node;
				}
				if (!beg)beg = lnk;
				else{
					lnkage[beg].push_back(lnk);
					lnkage[lnk].push_back(beg);
				}
				node = "";
			}
			else{
				node += str[i][j];
				if (j == s - 1){
					if (pars[node]){
						lnk = pars[node];
					}
					else{
						pars[node] = ++top;
						lnk = pars[node];
						conv[lnk] = node;
					}
					lnkage[beg].push_back(lnk);
					lnkage[lnk].push_back(beg);
				}
			}
		}
	}

	string start, end;
	cin >> start >> end;

	int r[33];
	for (int i = 1; i < 33; i++)r[i] = -1;

	queue <int> q;
	q.push(pars[start]);

	r[pars[start]] = 0;

	while (!q.empty() && r[pars[end]] == -1){
		int f = q.front(); q.pop();

		for (int i = 0; i < lnkage[f].size(); i++){
			int nxt = lnkage[f][i];
			if (r[nxt] >= 0)continue;
			else{
				r[nxt] = f;
				q.push(nxt);
			}
		}
	}

	int srch = pars[end];
	if (r[srch] > 0){
		vector <string> ans;
		while (srch > 0){
			ans.push_back(conv[srch]);
			srch = r[srch];
		}
		for (int i = ans.size() - 1; i >= 0; i--){
			cout << ans[i];
			if (i)cout << " ";
		}
	}
	else{
		printf("no route found");
	}

	printf("\n");
}