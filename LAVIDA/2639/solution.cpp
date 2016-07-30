#include <stdio.h>

#include <iostream>
#include <string>

#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class ele{
public:
	int d, c, f;
	bool operator<(const ele &A)const{
		return c < A.c;
	}
};
string d[12];

int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){
		map <string, int> pars;
		for (int i = 1; i <= n; i++){
			cin >> d[i];
			pars[d[i]] = i;
		}

		vector <ele> trans[13];

		ele psh, pop;
		int in[12] = { 0 };
		for (int i = 1; i < n; i++){
			string l, a, r;
			int k;
			cin >> l >> a >> k >> r;
			psh.d = pars[r], psh.c = k, psh.f = 1; // (*)
			trans[pars[l]].push_back(psh);

			psh.f = 0; // (/)
			psh.d = pars[l];

			trans[pars[r]].push_back(psh);
		}

		for (int s = 1; s <= n; s++){ // start node
			bool used[12] = { 0 };

			vector <ele> ans;
			queue <ele> q;

			used[s] = true;
			psh.d = s, psh.c = 1;
			q.push(psh);
			ans.push_back(psh);

			while (!q.empty()){
				pop = q.front(); q.pop();

				for (int i = 0; i < trans[pop.d].size(); i++){
					psh = trans[pop.d][i];
					if (used[psh.d])continue;
					else{
						if (psh.f == 1){
							used[psh.d] = true;
							psh.c *= pop.c;
							ans.push_back(psh);
							q.push(psh);
						}
						else{
							if (pop.c % psh.c)continue; // can't go

							used[psh.d] = true;
							psh.c = pop.c / psh.c;
							ans.push_back(psh);
							q.push(psh);
						}
					}
				}
			}

			if (ans.size() == n){
				sort(ans.begin(), ans.end());

				for (int i = 0; i < ans.size(); i++){
					cout << ans[i].c << d[ans[i].d];
					if (i < ans.size() - 1)printf(" = ");
				}printf("\n");
				break;
			}
		}
	}
}