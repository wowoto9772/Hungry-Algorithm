#include <stdio.h>
#include <memory.h>

#include <vector>
#include <algorithm>

using namespace std;

class ele{
public:
	int a, c;
	bool operator<(const ele &A)const{
		return c < A.c;
	}
};

vector < vector <int> > F, R, X;

int n, m, top;

bool v[10003];
int stk[10003]; // for finding cycle

int G[10003]; // group id
int g; // group cnt

void DFN(int a){
	v[a] = true;
	for (int i = 0; i < F[a].size(); i++){
		if (v[F[a][i]])continue;
		DFN(F[a][i]);
	}
	stk[top++] = a;
}

void CYC(int a){
	G[a] = g;
	X[g].push_back(a); // g's member is a
	for (int i = 0; i < R[a].size(); i++){
		if (!G[R[a][i]]){
			CYC(R[a][i]);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	F.resize(n + 1), R.resize(n + 1), X.resize(n + 1);

	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		F[a].push_back(b); // forward
		R[b].push_back(a); // backward
	}

	top = 0;
	for (int i = 1; i <= n; i++){
		if (!v[i])DFN(i);
	}

	g = 0;
	vector <ele> ans;
	for (int i = top - 1; i >= 0; i--){
		if (!G[stk[i]]){
			g++;
			CYC(stk[i]);
			sort(X[g].begin(), X[g].end());
			ele psh;
			psh.a = g, psh.c = X[g][0];
			ans.push_back(psh);
		}
	}
	
	sort(ans.begin(), ans.end());

	printf("%d\n", g);
	for (int i = 0; i < ans.size(); i++){
		for (int j = 0; j < X[ans[i].a].size(); j++){
			printf("%d ", X[ans[i].a][j]);
		}printf("-1\n");
	}
}