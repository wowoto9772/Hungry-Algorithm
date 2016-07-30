#include <stdio.h>
#include <vector>

using namespace std;

int I[100003];

class BIT{
public:
	vector <int> T;
	int S;
	BIT(const int &n){
		S = n;
		T.resize(S + 1);
	}
	void update(int p, int v){
		while (p <= S){
			T[p] += v;
			p += p & (-p);
		}
	}
	int sum(int p){
		int ret = 0;
		while (p){
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};


int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		BIT tree(n+m+1);

		for (int i = 1; i <= n; i++){
			tree.update(m+i, 1);
			I[i] = m + i;
		}

		int x = m;

		for (int i = 1; i <= m; i++){
			int a;
			scanf("%d", &a);

			tree.update(I[a], -1);
			printf("%d", tree.sum(I[a]));
			if (i < m)printf(" ");
			I[a] = x--;
			tree.update(I[a], 1);
		}printf("\n");
	}
}