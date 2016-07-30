#include <stdio.h>
#include <limits.h>

#include <vector>

using namespace std;

int m(int a, int b){ return a < b ? a : b; }
int M(int a, int b){ return a < b ? b : a; }

class RmMQ{ // range minimum or maximum query; Segment Tree
public:
	int n;

	vector <int> rangeMin, rangeMax;
	RmMQ(const vector <int> &arr){
		n = arr.size();
		rangeMin.resize(n * 4 + 1);
		rangeMax.resize(n * 4 + 1);
		init(arr, 0, n - 1, 1, 0);
		init(arr, 0, n - 1, 1, 1);
	}

	int init(const vector <int> &arr, int L, int R, int node, int flag){
		if (L == R){
			if (flag)return rangeMin[node] = arr[L];
			else
				return rangeMax[node] = arr[L];
		}

		int mid = (L + R) / 2;
		
		if (flag)return rangeMin[node] = m(init(arr, L, mid, node * 2, flag), init(arr, mid + 1, R, node * 2 + 1, flag));
		else
			return rangeMax[node] = M(init(arr, L, mid, node * 2, flag), init(arr, mid + 1, R, node * 2 + 1, flag));
	}

	int query(int L, int R, int node, int nodeL, int nodeR, int flag){
		if (R < nodeL || nodeR < L){
			if (flag)return INT_MAX;
			else
				return INT_MIN;
		}

		if (L <= nodeL && nodeR <= R){
			if (flag)return rangeMin[node];
			else
				return rangeMax[node];
		}

		int mid = (nodeL + nodeR) / 2;
		
		if (flag)return m(query(L, R, node * 2, nodeL, mid, flag), query(L, R, node * 2 + 1, mid + 1, nodeR, flag));
		else
			return M(query(L, R, node * 2, nodeL, mid, flag), query(L, R, node * 2 + 1, mid + 1, nodeR, flag));
	}

	int query(int L, int R, int flag){ return query(L, R, 1, 0, n - 1, flag); }

	int update(int index, int newV, int node, int nodeL, int nodeR, int flag){
		if (index < nodeL || nodeR < index){
			if (flag)return rangeMin[node];
			else
				return rangeMax[node];
		}

		if (nodeL == nodeR){
			if (flag)return rangeMin[node] = newV;
			else
				return rangeMax[node] = newV;
		}

		int mid = (nodeL + nodeR) / 2;
		if (flag)return rangeMin[node] = m(update(index, newV, node * 2, nodeL, mid, flag), update(index, newV, node * 2 + 1, mid + 1, nodeR, flag));
		else
			return rangeMax[node] = M(update(index, newV, node * 2, nodeL, mid, flag), update(index, newV, node * 2 + 1, mid + 1, nodeR, flag));
	}

	int update(int index, int newV, int flag){ return update(index, newV, 1, 0, n - 1, flag); }
};

void swp(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		vector <int> x;
		x.resize(n);

		for (int i = 0; i < n; i++)x[i] = i;
		RmMQ T(x);

		for (int i = 1; i <= m; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if (a){
				//printf("%d %d\n", T.query(b, c, 1), T.query(b, c, 0));
				if (b == T.query(b, c, 1) && c == T.query(b, c, 0))printf("YES\n");
				else
					printf("NO\n");
			}
			else{
				swp(&x[b], &x[c]);
				T.update(b, x[b], 0);
				T.update(b, x[b], 1);
				T.update(c, x[c], 0);
				T.update(c, x[c], 1);
			}
		}
	}
}