#include <stdio.h>
#include <map>
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

int c[1003];

int main() {

	map < int, map<int, bool> > chk;

	int n = 1000;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int gi = i, gj = j;
			int g = gcd(gi, gj);
			gi /= g, gj /= g;

			if (!chk[gi][gj]) {
				chk[gi][gj] = true;
				c[max(i, j)] += 2;
			}
		}
	}

	for (int i = 2; i <= n; i++)c[i] += c[i - 1];

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%d", &n);

		printf("%d\n", c[n]+3);

	}

}