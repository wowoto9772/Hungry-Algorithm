#include <stdio.h>
#include <algorithm>

using namespace std;

int s[300003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}

	sort(s, s + n);

	int Mval = 0;

	int k = 0, c = 0;

	for (int i = n - 1; i >= 0; i--) {
		
		++k;

		if (s[i] + n >= Mval)c++;

		s[i] = s[i] + k;

		Mval = max(Mval, s[i]);

	}

	printf("%d\n", c);

}