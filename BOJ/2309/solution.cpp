#include <stdio.h>
#include <algorithm>

using namespace std;

int d[13];

int main() {

	int n = 9;
	int s = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &d[i]);
		s += d[i];
	}

	for (int i = 3; i < (1 << n); i++) {
		int k = 0;
		int m = 0;
		for (int j = 0; j < n && k < 3; j++) {
			if (i&(1 << j)) {
				k++;
				m -= d[j];
			}
		}
		if (k == 2 && s + m == 100) {

			int o[9];
			int t = 0;

			for (int j = 0; j < n; j++) {
				if (i&(1 << j))continue;
				o[t++] = d[j];
			}

			sort(o, o + t);

			for (int j = 0; j < t; j++)printf("%d\n", o[j]);

			return 0;

		}
	}

}