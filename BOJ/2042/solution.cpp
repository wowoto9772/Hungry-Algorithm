#include <stdio.h>

#include <vector>

using namespace std;

class BIT{ // Binary Indexed Tree; Fenwicked Tree
public:
	vector <long long> ival; // interval
	BIT(const vector <int> &arr){
		int n = arr.size();
		ival.resize(n+1);

		for (int i = 1; i <= n; i++)add(i, arr[i-1]);
	}

	long long sum(int p){
		long long ret = 0;
		while (p > 0){
			ret += ival[p];
			p &= (p - 1);
			// to find the next interval, 
			// remove the last bit
		}return ret;
	}

	void add(int p, int v){
		int l = ival.size();
		while (p < l){
			ival[p] += v;
			p += (p & -p); // -p : p's 2's complement
		}
	}
};

void swp(int *a, int *b){
	if (*a > *b){
		int t = *a;
		*a = *b;
		*b = t;
	}
}

int main()
{
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	vector <int> x;
	x.resize(n);

	for (int i = 0; i < n; i++)scanf("%d", &x[i]);

	BIT k(x);

	for (int i = 1; i <= a + b; i++){
		int c, d, e;
		scanf("%d %d %d", &c, &d, &e);

		if (c % 2){
			k.add(d, -x[d-1]);
			x[d-1] = e;
			k.add(d, x[d-1]);
		}
		else{
			swp(&d, &e);
			printf("%lld\n", k.sum(e) - k.sum(d - 1));
		}
	}
}