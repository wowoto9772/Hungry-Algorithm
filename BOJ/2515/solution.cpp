#include <stdio.h>
#include <limits.h>

#include <algorithm>
#include <vector>

using namespace std;

class ele{
public:
	int h, v;
	bool operator<(const ele &A)const{
		if (h == A.h)return v > A.v;
		return h < A.h;
	}
}I[300003];

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

int main(){
	I[0].h = -30000001, I[0].v = 0;
	int n, t;
	scanf("%d %d", &n, &t);

	for (int i = 1; i <= n; i++){
		scanf("%d %d", &I[i].h, &I[i].v);
	}

	vector <int> tmp;
	tmp.resize(n+1);
	sort(I+1, I+1+n);

	RmMQ tree(tmp);

	for (int i = 1; i <= n; i++){
		int l = 0, r = i - 1, m;
		int cmp = I[i].h - t;
		while (l <= r){
			m = (l + r) / 2;
			if (I[m].h < cmp){
				l = m + 1;
			}
			else if (I[m].h > cmp){
				r = m - 1;
			}
			else
				break;
		}

		if (I[m].h > I[i].h - t)m--;

		int d = tree.query(0, m, 1) + I[i].v;

		tree.update(i, d, 1);
	}

	printf("%d\n", tree.query(0, n, 1));
}

