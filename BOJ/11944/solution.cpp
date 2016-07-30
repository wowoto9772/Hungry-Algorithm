#include <stdio.h>
#include <algorithm>

using namespace std;

char str[6];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	int top = 0;
	int cn = n;

	while (cn) {

		str[top++] = cn % 10 + '0';
		cn /= 10;

	}

	reverse(str, str + top);

	int cnt = top * n;

	int k = 0;
	for (int i = 1; i <= min(cnt, m); i++) {
		printf("%c", str[k]);
		k++;
		k %= top;
	}

}