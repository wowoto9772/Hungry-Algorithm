#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;

vector < vector <int> > L;
int C[1003][1003];
int A[1003][1003];
int s;

bool chk[1003];

void X(int c, int m){
	chk[c] = true;
	for (int i = 0; i < L[c].size(); i++){
		int n = L[c][i];
		if (!chk[n]){
			X(n, m + C[c][n]);
		}
	}
	A[s][c] = m;
}

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);

	L.resize(n + 1);

	for (int i = 1; i < n; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		L[a].push_back(b);
		L[b].push_back(a);
		C[a][b] = C[b][a] = c;
	}

	for (int i = 1; i <= n; i++){
		memset(chk, 0, sizeof(chk));
		s = i;
		X(i, 0);
	}

	for (int i = 1; i <= q; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", A[a][b]);
	}
}