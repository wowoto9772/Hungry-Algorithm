#include <stdio.h>

#define ll long long

ll k[80] = { 1, 1, 2, 4, };

ll dy(int c) {
	
	if (k[c])return k[c];

	return k[c] = dy(c - 1) + dy(c - 2) + dy(c - 3) + dy(c - 4);

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int x;
		scanf("%d", &x);

		printf("%lld\n", dy(x));

	}

}