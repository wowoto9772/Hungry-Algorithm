#include <cstdio>
#include <string>

#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = (1 << 31) - 1;

class ele {
public:
	string name;
	int cnt;
	bool operator<(const ele &A)const {
		if (cnt == A.cnt)return name < A.name;
		return cnt > A.cnt;
	}
}e[1003];

class dat {
public:
	int a, c;
	dat() {}
	dat(int _a, int _c) {
		a = _a, c = _c;
	}
	bool operator<(const dat &A)const {
		return c > A.c;
	}
};

int d[1003];
char str[13];

int main()
{

	int t, tc = 0;
	scanf("%d", &t);

	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);

		map <string, int> id;
		int top = 0;

		vector < int > L[1003];

		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			e[i].name = string(str);
			e[i].cnt = 0;
			if (id[e[i].name] == NULL) {
				id[e[i].name] = ++top;
			}
			int k;
			scanf("%d", &k);
			for (int j = 1; j <= k; j++) {
				scanf("%s", str);
				string _str = string(str);
				if (id[_str] == NULL) {
					id[_str] = ++top;
				}
				L[id[e[i].name]].push_back(id[_str]);
			}
		}

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= top; j++)d[j] = INF;

			priority_queue <dat> q;
			d[id[e[i].name]] = 0;
			q.emplace(id[e[i].name], 0);

			while (!q.empty()) {
				dat cur = q.top(); q.pop();
				if (d[cur.a] < cur.c)continue;
				for (int j = 0; j < L[cur.a].size(); j++) {
					dat nxt = { L[cur.a][j], cur.c + 1 };
					if (d[nxt.a] > nxt.c) {
						d[nxt.a] = nxt.c;
						q.emplace(nxt);
					}
				}
			}

			for (int j = 1; j <= top; j++) {
				if (d[j] == m)e[i].cnt++;
			}
		}

		sort(e + 1, e + 1 + top);

		printf("Tree %d:\n", ++tc);

		int i;
		for (i = 1; i <= 3 && i <= top; i++) {
			if (!e[i].cnt)break;
			printf("%s %d\n", e[i].name.c_str(), e[i].cnt);
		}
		for (; i <= top; i++) {
			if (!e[i].cnt)break;
			if (e[i].cnt == e[i - 1].cnt)printf("%s %d\n", e[i].name.c_str(), e[i].cnt);
			else
				break;
		}
		printf("\n");
	}
}