#include <stdio.h>

#include <vector>

using namespace std;

class BIT{
public:
	vector <long long> iv;
	BIT(const vector <int> &arr){
		int n = arr.size();
		iv.resize(n + 1);

		for (int i = 1; i <= n; i++)add(i, arr[i - 1]);
	}

	long long sum(int p){
		long long ret = 0;
		while (p > 0){
			ret += iv[p];
			p &= (p - 1);
		}return ret;
	}

	void add(int p, int v){
		int l = iv.size();
		while (p < l){
			iv[p] += v;
			p += (p & -p);
		}
	}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector <int> x;
	x.resize(n);

	BIT tr(x);

	for (int i = 1; i <= m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a){ // edit
			tr.add(b, -x[b - 1]);
			x[b-1] = c;
			tr.add(b, x[b - 1]);
		}
		else{	// sum
			if (b > c){
				int k = b;
				b = c;
				c = k;
			}
			printf("%lld\n", tr.sum(c) - tr.sum(b - 1));
		}
	}
}