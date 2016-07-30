#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector <int> v;

	int n = 1500000;

	for (int i = 1; i <= n; i++) {

		int c[10] = {};

		int k = i;

		while (k) {
			c[k % 10]++;
			k /= 10;
		}

		for (int j = 2; j*j <= i; j++) {

			if (i%j)continue;

			bool flag = false;

			int d[10] = {};

			k = j;
			while (k && !flag) {
				d[k % 10]++;
				if (c[k % 10] < d[k % 10])flag = true;
				k /= 10;
			}

			k = i / j;
			while (k && !flag) {
				d[k % 10]++;
				if (c[k % 10] < d[k % 10])flag = true;
				k /= 10;
			}

			if (!flag) {
				v.push_back(i);
				break;
			}

		}

	}

	while(scanf("%d", &n) == 1 && n){

		printf("%d\n", *lower_bound(v.begin(), v.end(), n));

	}

}