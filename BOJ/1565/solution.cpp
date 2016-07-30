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

int D[53], M[53];

int main() {

	int d, m;
	scanf("%d %d", &d, &m);

	bool flag = false;

	for (int i = 1; i <= d; i++) {
		scanf("%d", &D[i]);
		if (D[i] == 0)flag = true;
	}

	for (int i = 1; i <= m; i++)scanf("%d", &M[i]);

	int g = M[1];

	for (int i = 2; i <= m; i++) {
		if (M[i] == 0 || g == 0)flag = true;
		if (flag)continue;
		g = gcd(g, M[i]);
	}

	vector <int> k;

	if (!flag) {

		if (g == 1)k.push_back(1);
		else {
			for (int i = 1; i*i <= g; i++) {
				if (g%i)continue;
				k.push_back(i);
				if (i < g / i)k.push_back(g / i);
			}
		}

		sort(k.begin(), k.end());

		for (int i = 1; i <= d; i++) {
			for (int j = k.size() - 1; j >= 0; j--) {
				if (k[j] % D[i]) {
					k.erase(k.begin() + j);
				}
				else if (k[j] < D[i]) {
					k.erase(k.begin() + j);
				}
			}
		}

	}

	printf("%d\n", k.size());


}