#include <stdio.h>
#include <string.h>
#include <string>
#define ll long long

using namespace std;

char str[13];
ll tar, rem = 1;

int main() {

	scanf("%s", str);

	int s = strlen(str), p;

	p = s;

	for (int i = 0; i < s; i++) {
		tar = tar * 26 + (str[i] - 'A');
		rem *= 26LL;
	}

	int n;
	scanf("%d", &n);

	int ans = 0;

	for (int i = 0; i < n; i++) {
		scanf("%s", str);

		string cmp = string(str);
		cmp += cmp;

		int c = cmp.size();

		ll k = 0;

		for (int j = 0; j < c; j++) {
			
			k = k * 26 + cmp[j] - 'A';
			if (j >= p) {
				k -= rem * (str[j - p] - 'A');
			}
			if (j >= p - 1) {
				if (k == tar) {
					ans++;
					break;
				}
			}
		}
	}

	printf("%d\n", ans);

} // karp-rabin algorithm