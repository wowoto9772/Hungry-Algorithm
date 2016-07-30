#include <stdio.h>

int rev(int v) {
	int r = 0;

	while (v) {
		r = r * 10 + v % 10;
		v /= 10;
	}

	return r;
}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int v;
		scanf("%d", &v);

		v += rev(v);

		if (v == rev(v))printf("YES\n");
		else
			printf("NO\n");

	}

}