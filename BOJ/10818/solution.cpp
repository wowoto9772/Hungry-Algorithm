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
		rm.resize(4 * n + 1);
		rM.resize(4 * n + 1);
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
	int n;
	scanf("%d", &n);

	vector <int> a(n);

	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	RmMQ tree(a);

	printf("%d %d\n", tree.query(0, n-1, 0), tree.query(0, n-1, 1));
}