#include <stdio.h>
#include <memory.h>

#include <iostream>
#include <string>

#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class ele{
public:
	string name;
	int cnt;
	bool operator<(const ele &A)const{
		if (cnt == A.cnt)return name < A.name;
		return cnt > A.cnt;
	}
};

class dat{
public:
	int a, c;
};

int main()
{

	int t, a = 0;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		map <string, int> id;
		int top = 0;

		ele I[1003]; // 초기화 안해서 틀렸던 것...
		vector < int > L[1003];

		for (int i = 1; i <= n; i++){
			cin >> I[i].name;
			I[i].cnt = 0;
			if (id[I[i].name] == NULL){
				id[I[i].name] = ++top;
			}
			int k;
			scanf("%d", &k);
			for (int j = 1; j <= k; j++){
				string str;
				cin >> str;
				if (id[str] == NULL){
					id[str] = ++top;
				}
				L[id[I[i].name]].push_back(id[str]);
			}
		}


		for (int i = 1; i <= top; i++){

			int d[1003];
			memset(d, 0x2f, sizeof(d));

			queue <dat> Q;
			dat psh, pop;
			psh.a = id[I[i].name], psh.c = 0;
			d[psh.a] = 0;
			Q.push(psh);

			while (!Q.empty()){
				pop = Q.front(); Q.pop();
				for (int j = 0; j < L[pop.a].size(); j++){
					int nxt = L[pop.a][j];
					if (d[nxt] > pop.c + 1){
						d[nxt] = pop.c + 1;
						psh.a = nxt, psh.c = d[nxt];
						Q.push(psh);
					}
				}
			}

			for (int j = 1; j <= top; j++){
				if (d[j] == m)I[i].cnt++;
			}
		}

		sort(I + 1, I + 1 + top);

		printf("Tree %d:\n", ++a);
		int k = 1, i;
		for (i = 1; i <= 3 && i <= top; i++){
			if (!I[i].cnt)break;
			cout << I[i].name << " " << I[i].cnt << endl;
		}
		for (; i <= top; i++){
			if (!I[i].cnt)break;
			if (I[i].cnt == I[i - 1].cnt)cout << I[i].name << " " << I[i].cnt << endl;
			else
				break;
		}
		printf("\n");
	}
}