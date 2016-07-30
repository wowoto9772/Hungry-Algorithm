#include <stdio.h>

int q[103], s[103], b[103];

bool pos(int v) {

	bool c[10] = { true, };

	while (v) {
		int m = v % 10;
		if (!c[m]) {
			c[m] = true;
		}
		else
			return false;
		v /= 10;
	}

	return true;

}

int ball(int s, int t) {

	int a[3], b[3];

	int p = 0;

	while (s) {
		a[p++] = s % 10;
		s /= 10;
	}

	p = 0;
	while (t) {
		b[p++] = t % 10;
		t /= 10;
	}

	int r = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j)continue;
			if (a[i] == b[j])r++;
		}
	}

	return r;

}

int strike(int s, int t) {

	int r = 0;

	while (s) {
		if (s % 10 == t % 10)r++;
		s /= 10, t /= 10;
	}

	return r;

}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &q[i], &s[i], &b[i]);
	}

	int c = 0;

	for (int i = 123; i <= 987; i++) {

		if (!pos(i))continue;

		bool flag = false;

		for (int j = 1; !flag && j <= n; j++) {

			if (ball(i, q[j]) != b[j] || strike(i, q[j]) != s[j])flag = true;

		}

		if (!flag)c++;

	}

	printf("%d\n", c);

}