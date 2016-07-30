#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

#define ll long long
#define hash 1000000000007LL

char str[21003];

int main() {

	map <ll, int> h;
	ll a = 1, b = 1, c;
	h[1] = 2;
	for (int i = 3; i <= 120000; i++) {
		c = a + b;
		c %= hash;
		h[c] = i;
		a = b;
		b = c;
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%s", str);

		int s = strlen(str);
		ll k = 0;

		for (int i = 0; i < s; i++) {
			k = k * 10 + str[i] - '0';
			k %= hash;
		}

		printf("%d\n", h[k]);

	}

}