#include <stdio.h>

#include <map>

#include <deque>

#include <vector>

using namespace std;

map < int, map <int, bool> > dup;

vector < vector <int> > lnk[2];

vector < bool > vst;

deque < int > my[100003];

int nxt[100003];

int tot;

int in[100003], out[100003];

bool valid(int c, int m){

	if(my[c].empty())return false;

	if(tot == m){

		if(in[c] == 1 && out[c] == 1){
			c = my[c].back();
		}

		for(int i=0; i<lnk[0][c].size(); i++){
			if(lnk[0][c][i] == 1)return true;
		}

		return false;

	}

	bool ret = false;

	int lc = c;

	if(in[c] == 1 && out[c] == 1){
		lc = my[c].back();
	}

	for(int i=0; i<lnk[0][lc].size(); i++){
		int nc = lnk[0][lc][i];
		if(vst[nc] || my[nc].empty())continue;
		vst[nc] = true;
		ret = valid(nc, m+1);
		if(ret){
			nxt[c] = nc;
			return ret = true;
		}
		vst[nc] = false;
	}


	return ret;

}

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	for(int i=0; i<2; i++)lnk[i].resize(n+1);

	while(m--){

		int a, b;
		scanf("%d %d", &a, &b);

		if(a == b)continue;

		if(dup[a][b])continue;

		dup[a][b] = true;

		in[b]++;
		out[a]++;

		lnk[0][a].push_back(b);
		lnk[1][b].push_back(a);

	}

	for(int i=1; i<=n; i++)if(lnk[0][i].empty()){
		printf("There is no route, Karl!\n");
		return 0;
	}

	vector < bool > comp;
	comp.resize(n+1);

	for(int i=1; i<=n; i++){

		if(comp[i])continue;

		tot++;

		if(in[i] == 1 && out[i] == 1){

			comp[i] = true;

			deque <int> q;

			q.push_back(i);

			int l = i, r = i;

			while(true){

				if(lnk[0][r].size() != 1)break;

				r = lnk[0][r].back();

				if(in[r] == 1 && out[r] == 1){
					if(comp[r])break;
					comp[r] = true;
					q.push_back(r);
				}else{
					break;
				}

			}

			while(true){

				if(lnk[1][l].size() != 1)break;

				l = lnk[1][l].back();

				if(in[l] == 1 && out[l] == 1){
					if(comp[l])break;
					comp[l] = true;
					q.push_front(l);
				}else{
					break;
				}

			}

			my[q.front()] = q;

		}else{
			my[i] = {i};
		}

	}

	vst.resize(n+1);

	vst[1] = true;

	bool flag = valid(1, 1);

	if(flag){

		int c = 1, s = 1;
		for(auto &v : my[c])printf("%d ", v);

		while(s < tot){

			int nc = nxt[c];
			for(auto &v : my[nc])printf("%d ", v);
			c = nc;

			s++;

		}

		printf("1");
	}else{
		printf("There is no route, Karl!");
	}

}
