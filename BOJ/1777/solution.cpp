#include <stdio.h>
#include <vector>

using namespace std;

class BIT{
public:
	vector <int> T;
	int S;
	BIT(const int n){
		S = n;
		T.resize(S + 1);
	}
	void Update(int p, int v){
		while (p <= S){
			T[p] += v;
			p += p & (-p);
		}
	}
	long long Sum(int p){
		long long ret = 0;
		while (p > 0){
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};

int I[100003];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &I[i]);
		// in sequence, after i, the number of less than i

		I[i] = (i - 1) - I[i];
		// in sequence, before i, the number of less than i
	}

	vector <int> ans(n);

	BIT tree(n);
	for (int i = n; i >= 1; i--){
		int p = I[i];
		p += 1;
		int add = tree.Sum(p);
		if (!add){
			tree.Update(p, 1);
			ans[p - 1] = i;
		}
		else{
			int l = p, r = n, m;
			while (l <= r){
				m = (l + r) / 2;
				if (m - tree.Sum(m) >= p){
					r = m - 1;
				}
				else{
					l = m + 1;
				}
			}

			if (m - tree.Sum(m) < p)m++;
			p = m;
			tree.Update(p, 1);
			ans[p - 1] = i;
		}


	}

	for (int i = 0; i < n - 1; i++)printf("%d ", ans[i]);
	printf("%d\n", ans[n - 1]);
} 

/*
0 0 2 1 2 4 4 7
2 4 5 1 7 6 3 8
*/