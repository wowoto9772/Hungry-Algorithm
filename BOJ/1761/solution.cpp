#include <stdio.h>
#include <limits.h>
#include <vector>

using namespace std;

#define NOD_MAX (40000 + 3)

class ele{
public:
	int a, c;
};

vector < vector <ele> > lnk;

int id[NOD_MAX]; // leftmost position what X
int cost[NOD_MAX]; // cost from root to X

int level[NOD_MAX * 2]; // level from root to X
int order[NOD_MAX * 2]; // tree traversal's order

int top;

void traversal(int cur, int pre, int dep){ // root ~ 
	id[cur] = top; // leftmost position cur's id number
	order[top] = cur;
	level[top] = dep;
	top++;

	for (int i = 0; i < lnk[cur].size(); i++){
		ele pop = lnk[cur][i];
		if (pop.a != pre){
			cost[pop.a] = cost[cur] + pop.c;
			traversal(pop.a, cur, dep + 1);
			order[top] = cur;
			level[top] = dep;
			top++;
		}
	}
}

class RmMQ{
public:

	int n;

	class mydual{
	public:
		int lev, ind;
		mydual(){
			lev = ind = 0;
		}
		mydual(int level, int index){
			lev = level, ind = index;
		}
	};

	vector <mydual> rM, rm;

	RmMQ(vector <int> &I, vector <int> &J){ // I : level, J : index
		n = I.size();
		rm.resize(4 * n + 1, { 0, 0 });
		init(I, J, 1, 0, n - 1, 0); // Range Minimum Query
		//rM.resize(4 * n + 1);
		//init(I, 1, 0, n - 1, 1); // Range Maximum Query
	}

	mydual max(mydual a, mydual b){ return a.lev > b.lev ? a : b; }
	mydual min(mydual a, mydual b){ return a.lev < b.lev ? a : b; }

	mydual init(vector <int> &I, vector <int> &J, int x, int xl, int xr, int isMax){ // level, index
		if (xl == xr){
			if (isMax)return rM[x] = { I[xl], J[xl] };
			else{
				return rm[x] = { I[xl], J[xl] };
			}
		}
		else{
			int m = (xl + xr) / 2;
			if (isMax){
				return rM[x] = max(init(I, J, x * 2, xl, m, isMax), init(I, J, x * 2 + 1, m + 1, xr, isMax));
			}
			else{
				return rm[x] = min(init(I, J, x * 2, xl, m, isMax), init(I, J, x * 2 + 1, m + 1, xr, isMax));
			}
		}
	}

	mydual query(int il, int ir, int x, int xl, int xr, int isMax){
		if (ir < xl || xr < il){
			if (isMax)return{ INT_MIN, n-1 };
			else
				return{ INT_MAX, n-1 };
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

	mydual query(int il, int ir, int isMax){
		return query(il, ir, 1, 0, n - 1, isMax);
	}
};

int A(int a){ return a < -a ? -a : a; }

int main(){
	int n;
	scanf("%d", &n);

	lnk.resize(n + 1);

	ele psh;
	for (int i = 1; i < n; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		psh.a = b, psh.c = c;
		lnk[a].push_back(psh);
		psh.a = a;
		lnk[b].push_back(psh);
	}

	// these nodes make tree. So, all nodes can be root
	traversal(1, 0, 1);

	vector <int> lev, ord;
	for (int i = 0; i < top; i++){
		lev.push_back(level[i]);
		ord.push_back(order[i]);
	}

	RmMQ tree(lev, ord);

	int q;
	scanf("%d", &q);

	for (int i = 1; i <= q; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		int ia = id[a], ib = id[b];
		if (ia > ib){
			int k = ia;
			ia = ib;
			ib = k;
		}
		int lca = tree.query(ia, ib, 0).ind; // least common ancestor

		int ans = (cost[a] - cost[lca]) + (cost[b] - cost[lca]);

		printf("%d\n", ans);
	}
}