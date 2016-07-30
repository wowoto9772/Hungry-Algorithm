#include <stdio.h>
#include <vector>

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

int main() {

	int r, g;
	scanf("%d %d", &r, &g);

	int d = gcd(r, g);

	vector <int> v;

	for (int i = 1; i*i <= d; i++) {
		if (d%i)continue;
		v.push_back(i);
		if (d / i != i)v.push_back(d / i);
	}

	for (int i = 0; i < v.size(); i++) {
		printf("%d %d %d\n", v[i], r / v[i], g / v[i]);
	}

}