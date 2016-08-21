#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	
	int m = 1;
	
	while (m) {
		m = a % b;
		a = b;
		b = m;
	}
	
	return a;

}

int nCk(int n, int k) {

	vector <int> d;

	k = min(k, n - k);

	for (int i = k; i > 1; i--) {
		d.push_back(i);
	}

	int ret = 1;

	for (int i = n; i > n - k; i--) {

		int v = i;

		for (int j = 0; j < d.size(); j++) {

			int g = gcd(d[j], v);

			v /= g;
			d[j] /= g;

		}

		ret *= v;

	}

	return ret;

}

int main() {

	int n, k;
	while (scanf("%d %d", &n, &k) == 2) {

		if (!(n | k))break;

		printf("%d\n", nCk(n, k));

	}
	
}