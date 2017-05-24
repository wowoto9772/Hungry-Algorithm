#include <cstdio>
#include <limits.h>

#include <vector>
#include <algorithm>

#define le(x) (x<<1)
#define ri(x) ((x<<1)|1)

using namespace std;

class RmMQ{
public:
	int n;
	vector <int> rM, rm;

	RmMQ(const vector <int> &e){
		n = e.size();
		rm.resize(n << 1);
		rM.resize(n << 1);
		// init(e, 1, 0, n - 1, 1); // Range Maximum Query
		init(e, 1, 0, n - 1, 0); // Range Minimum Query
	} // O(2*n-1)

	int init(const vector <int> &e, int x, int xl, int xr, int isMax){
		if (xl == xr){
			if (isMax)return rM[x] = e[xl];
			else{
				return rm[x] = e[xl];
			}
		}
		else{
			int m = (xl + xr) / 2;
			if (isMax){
				return rM[x] = max(init(e, x * 2, xl, m, isMax), init(e, x * 2 + 1, m + 1, xr, isMax));
			}
			else{
				return rm[x] = min(init(e, x * 2, xl, m, isMax), init(e, x * 2 + 1, m + 1, xr, isMax));
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
};
int main(){
	
	int n, m;
	scanf("%d", &n);
	
	vector <int> v(n);
	
	for(int i=0; i<n; i++)scanf("%d", &v[i]);
	int s = 1;
	while(s < n)s <<= 1;
	while(s != n){
		v.push_back(INT_MAX);
		s--;	
	}
	
	RmMQ tree(v);
	
	scanf("%d", &m);
	
	while(m--){
		int a, x, y;
		scanf("%d %d %d", &a, &x, &y);
		x--;
		if(a == 1){
			tree.update(x, y, 0);
		}else{
			y--;
			if(x > y)swap(x, y);
			printf("%d\n", tree.query(x, y, 0));
		}
	}
	
}