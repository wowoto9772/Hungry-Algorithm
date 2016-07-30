#include <stdio.h>
#include <limits.h>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

class Segment{
public:
	int L;
	int S;
	vector <int> c;
	bool chk[20002];

	Segment(const int &n, int &l){
		L = l;
		S = n;
		c.resize(S * 4);
		memset(chk, 0, sizeof(chk));
	}

	void update(int il, int ir, int v, int x, int xl, int xr){
		if (il > xr || ir < xl)return;
		if (il <= xl && xr <= ir){
			c[x] = v;
		}
		else{
			int m = (xl + xr) / 2;
			update(il, ir, v, x * 2, xl, m);
			update(il, ir, v, x * 2 + 1, m + 1, xr);
		}
	}

	int max(int a, int b){ return a < b ? b : a; }

	void query(int B, int x, int xl, int xr){
		int m = (xl + xr) / 2;
		if (xl == xr){
			chk[B] = true;
			return;
		}
		query(max(B, c[x * 2]), x * 2, xl, m);
		query(max(B, c[x * 2 + 1]), x * 2 + 1, m+1, xr);
	}

	int ans(){
		int ret = 0;
		for (int i = 1; i <= 20000; i++)ret += chk[i] ? 1 : 0;
		return ret;
	}
};

class ele{
public:
	int l, r;
}I[10003];

int main()
{
		int n;
		scanf("%d", &n);

		int top = 0;

		vector <int> x;

		for (int i = 1; i <= n; i++){
			scanf("%d %d", &I[i].l, &I[i].r);
			x.push_back(I[i].l);
			x.push_back(I[i].r);
		}

		sort(x.begin(), x.end());
		x.resize(distance(x.begin(), unique(x.begin(), x.end())));

		Segment tree(x.size(), n);
		for (int i = 1; i <= n; i++){
			int l = 0, r = x.size() - 1, m, m2;
			while (l <= r){
				m = (l + r) / 2;
				if (x[m] < I[i].l)l = m + 1;
				else if (x[m] > I[i].l)r = m - 1;
				else
					break;
			}
			l = 0, r = x.size() - 1;
			while (l <= r){
				m2 = (l + r) / 2;
				if (x[m2] < I[i].r)l = m2 + 1;
				else if (x[m2] > I[i].r)r = m2 - 1;
				else
					break;
			}
			tree.update(m, m2, ++top, 1, 0, x.size() - 1);
		}
		tree.query(tree.c[1], 1, 0, x.size() - 1);
		printf("%d\n", tree.ans());
	}
