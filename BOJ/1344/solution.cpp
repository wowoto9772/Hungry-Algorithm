#include <stdio.h>

bool isPrime(int v) {
	if (v < 2)return false;
	else if (v == 2)return true;
	else {
		if (!(v % 2))return false;
		else {
			for (int i = 3; i*i <= v; i += 2) {
				if (v%i)continue;
				return false;
			}return true;
		}
	}
}

double dp[20][20][20];
double a, b;

double dy(int l, int r, int t) {

	if (t == 18) {
		if (isPrime(l) || isPrime(r))return 1.0;
		return 0.0;
	}

	double &ret = dp[l][r][t];

	if (ret >= 0.0)return ret;

	ret = 0.0;

	ret += a * (1.0 - b) * dy(l + 1, r, t + 1);
	ret += (1.0 - a) * b * dy(l, r + 1, t + 1);
	ret += a * b * dy(l + 1, r + 1, t + 1);
	ret += (1.0 - a) * (1.0 - b) * dy(l, r, t + 1);

	return ret;

}

int main() {

	for (int i = 0; i <= 18; i++) {
		for (int j = 0; j <= 18; j++) {
			for (int k = 0; k < 18; k++) {
				dp[i][j][k] = -1.0;
			}
		}
	}

	scanf("%lf %lf", &a, &b);

	a /= 100.0, b /= 100.0;

	printf("%.9lf\n", dy(0, 0, 0));

}