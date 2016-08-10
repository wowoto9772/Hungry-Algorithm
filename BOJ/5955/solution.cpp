#include <stdio.h>
#include <limits.h>

#include <queue>
#include <vector>

using namespace std;

class ele {
public:
	ele() {}
	ele(int _a, int _c){
		a = _a, c = _c;
	}

	int a, c; // arrival and cost || Blue and Purple cycle
	int f;    // first remain time
	int t;    // type 0 is blue

	bool operator<(const ele &A)const {
		return c > A.c;
	}
}edge[303];

bool TheTime(int t, int w) {
	if (t >= edge[w].f) {
		t -= edge[w].f;
		t %= edge[w].a + edge[w].c;
		if (edge[w].t) { // is purple
			if (t < edge[w].a)return 0;
			else
				return 1;
		}
		else {		 // is blue
			if (t < edge[w].c)return 1;
			else
				return 0;
		}
	}
	else {
		return edge[w].t;
	}
}

int main()
{
	int S, D;
	scanf("%d %d", &S, &D);

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		char a;
		int b, c, d;
		scanf(" %c %d %d %d", &a, &b, &c, &d);

		edge[i].a = c, edge[i].c = d, edge[i].f = b;

		if (a == 'B')edge[i].t = 0;
		else
			edge[i].t = 1;
	}

	vector < vector < ele > > L;
	L.resize(N + 1);

	for (int i = 1; i <= M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		L[a].emplace_back(b, c);
		L[b].emplace_back(a, c);
	}

	int d[303];
	for (int i = 1; i <= N; i++)d[i] = INT_MAX;
	d[S] = 0;

	priority_queue <ele> Q;
	Q.emplace(S, 0);

	while (!Q.empty()) {
		
		ele f = Q.top(); Q.pop();

		if (d[f.a] > f.c)continue;

		for (int i = 0; i < L[f.a].size(); i++) {

			ele g = L[f.a][i];

			ele pre = edge[f.a], pst = edge[g.a];

			int t = pre.a + pre.c;
			if (t < pst.a + pst.c)t = pst.a + pst.c;

			for (int k = 0; k <= 2 * t; k++) {
				int cst = f.c + k;
				if (TheTime(cst, f.a) == TheTime(cst, g.a)) {
					cst += g.c;
					if (d[g.a] > cst) {
						d[g.a] = cst;
						g.c = cst;
						Q.push(g);
					}
					break;
				}
			}

		}
	}

	if (d[D] == INT_MAX)d[D] = 0;

	printf("%d\n", d[D]);
}

/*
a -> b is same color	  : just go
different color : wait ... when?
finding the time
that two things's color are same
*/