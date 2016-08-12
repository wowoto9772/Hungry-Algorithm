#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

char typ[23];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		int top = 0;

		vector <long long> c;

		c.push_back(0);

		map <string, int> mp;

		for (int i = 1; i <= n; i++) {
			
			scanf("%*s %s", typ);
			
			string tmp = string(typ);

			if (!mp[tmp]) {
				mp[tmp] = ++top;
				c.push_back(0);
			}

			c[mp[tmp]]++;

		}

		long long ans = 1;

		for (int i = 1; i <= top; i++) {
			ans *= (c[i] + 1);
		}

		ans--;

		printf("%lld\n", ans);

	}

}