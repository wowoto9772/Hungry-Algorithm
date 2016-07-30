#include <stdio.h>
#include <vector>

#include <algorithm>

using namespace std;

#define ll long long

int main() {

	ll a, b;
	while (scanf("%lld %lld", &a, &b) == 2) {

		if (!(a | b))break;

		vector <int> x;

		if (!a)x.push_back(0);
		else {
			while (a) {
				x.push_back(a % 10);
				a /= 10;
			}
		}

		vector <int> y;

		if (!b)y.push_back(0);
		else {
			while (b) {
				y.push_back(b % 10);
				b /= 10;
			}
		}

		int s = x.size() - y.size();

		if (s < 0) {
			for (int i = 1; i <= (s*-1); i++)x.push_back(0);
		}
		else if (s > 0) {
			for (int i = 1; i <= s; i++)y.push_back(0);
		}

		x.push_back(0);
		y.push_back(0);

		int up = 0;

		for (int i = 0; i < y.size(); i++) {
			x[i] += y[i];
			if (x[i] >= 10) {
				x[i + 1] += (x[i]) / 10;
				x[i] %= 10;
				up++;
			}
		}

		printf("%d\n", up);

	}

}