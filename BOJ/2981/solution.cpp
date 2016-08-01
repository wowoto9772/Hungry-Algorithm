#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int e[103];

int gcd(int a, int b) {

	int m = 1;

	while (m) {
		m = a % b;
		a = b;
		b = m;
	}

	return a;
}

int main() {

	int n;
	scanf("%d", &n);

	int g;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &e[i]);
	}

	sort(e + 1, e + 1 + n);

	g = e[2] - e[1];
	for (int i = 3; i <= n; i++) {
		g = gcd(g, e[i] - e[i - 1]);
	}

	vector <int> v;

	for (int i = 1; i <= g / i; i++) {
		if (g%i)continue;
		v.push_back(i);
		if (i != g / i)v.push_back(g / i);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i < v.size(); i++)printf("%d ", v[i]);

}