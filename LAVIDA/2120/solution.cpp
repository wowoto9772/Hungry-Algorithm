#include <stdio.h>
#include <limits.h>
#include <vector>

using namespace std;

class RmMQ{
public:
	int n;
	vector <int> rM, rm;

	RmMQ(vector <int> &I){
		n = I.size();
		rM.resize(4 * n + 1);
		rm.resize(4 * n + 1);
		init(I, 1, 0, n - 1, 1); // Range Maximum Query
		init(I, 1, 0, n - 1, 0); // Range Minimum Query
	}

	int max(int a, int b){ return a < b ? b : a; }
	int min(int a, int b){ return a < b ? a : b; }

	int init(vector <int> &I, int x, int xl, int xr, int isMax){
		if (xl == xr){
			if (isMax)return rM[x] = I[xl];
			else{
				return rm[x] = I[xl];
			}
		}
		else{
			int m = (xl + xr) / 2;
			if (isMax){
				return rM[x] = max(init(I, x * 2, xl, m, isMax), init(I, x * 2 + 1, m + 1, xr, isMax));
			}
			else{
				return rm[x] = min(init(I, x * 2, xl, m, isMax), init(I, x * 2 + 1, m + 1, xr, isMax));
			}
		}
	}

	int update(int p, int v, int x, int xl, int xr, int isMax){
		if (p < xl || xr < p){
			if (isMax)return rM[x];
			else
				return rm[x];
		}
		else if (xl == xr){
			if (isMax)return rM[x] = v;
			else
				return rm[x] = v;
		}
		else{
			int m = (xl + xr) / 2;
			if (isMax)return rM[x] = max(update(p, v, x * 2, xl, m, isMax), update(p, v, x * 2 + 1, m + 1, xr, isMax));
			else{
				return rm[x] = min(update(p, v, x * 2, xl, m, isMax), update(p, v, x * 2 + 1, m + 1, xr, isMax));
			}
		}
	}

	int update(int p, int v, int isMax){
		return update(p, v, 1, 0, n - 1, isMax);
	}

	int query(int il, int ir, int x, int xl, int xr, int isMax){
		if (ir < xl || xr < il){
			if (isMax)return INT_MIN;
			else
				return INT_MAX;
		}
		else if (il <= xl && xr <= ir){
			if (isMax)return rM[x];
			else
				return rm[x];
		}
		else{
			int m = (xl + xr) / 2;
			if (isMax)return max(query(il, ir, x * 2, xl, m, isMax), query(il, ir, x * 2 + 1, m + 1, xr, isMax));
			else
				return min(query(il, ir, x * 2, xl, m, isMax), query(il, ir, x * 2 + 1, m + 1, xr, isMax));
		}
	}

	int query(int il, int ir, int isMax){
		return query(il, ir, 1, 0, n - 1, isMax);
	}
};

int main()
{
	int t;
	scanf("%d", &t);
	
	while (t--){
		int n, q;
		scanf("%d %d", &n, &q);

		vector <int> x(n);

		for (int i = 0; i < n; i++){
			x[i] = i;
		}

		RmMQ tree(x);

		for (int i = 1; i <= q; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);

			if (!a){
				int k = x[b];
				x[b] = x[c];
				x[c] = k;
				tree.update(b, x[b], 1);
				tree.update(b, x[b], 0);
				tree.update(c, x[c], 1);
				tree.update(c, x[c], 0);
			}
			else{
				if (tree.query(b, c, 1) == c && tree.query(b, c, 0) == b){
					printf("YES\n");
				}
				else{
					printf("NO\n");
				}
			}
		}
	}
}