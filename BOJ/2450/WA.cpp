#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int o[100003], t[3];
int c[100003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < 3; i++)t[i] = i + 1;

	for (int i = 0; i < n; i++) {
		scanf("%d", &o[i]);
	}

	int ans = n;

	for (int i = 1; i <= 6; i++) {

		int x = 0;

		memcpy(c, o, sizeof(o));

		for (int j = 0; j <= 1; j++) {

			int l = 0, r = n - 1;

			if (j) {
				while (l < n && c[l] == t[0])l++;
			}

			while (l <= r) {

				while (l < n && c[l] == t[j])l++;

				if (l == n)break;

				while (r >= 0 && c[r] != t[j])r--;

				if (r == -1)break;

				if (l < r) {
					x++;
					swap(c[l], c[r]);
					l++, r--;
				}

			} // exchange 1:1

			// x z (x y, y z)

		}

		ans = min(ans, x);

		next_permutation(t, t + 3);
	}

	printf("%d\n", ans);

}