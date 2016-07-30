#include <stdio.h>

#include <vector>

#include <algorithm>

using namespace std;

int main()
{

	int n;
	scanf("%d", &n);

	vector <int> K(n);

	for (int i = 0; i < n; i++)scanf("%d", &K[i]);

	sort(K.begin(), K.end());

	long long ans = 0;

	int c = 0;
	int i = 1;

	while (i < n && c < n - 1) {

		if (K[i] * 9 <= K[c] * 10) {
			ans += i - c;
			i++;
		}
		else {
			c++;
		}

	}

	printf("%lld\n", ans);
}
