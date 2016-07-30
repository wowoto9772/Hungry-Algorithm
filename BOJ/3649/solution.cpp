#include <stdio.h>
#include <algorithm>

using namespace std;

int l[1000003];

int main() {

	int x;
	while (scanf("%d", &x) == 1) {

		x *= 10000000;

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)scanf("%d", &l[i]);
		l[n] = 1000000007;

		sort(l, l + n);

		bool flag = false;

		for (int i = 0; !flag && i < n; i++) {
			
			int tar = x - l[i];

			int v = lower_bound(l + i + 1, l + n, tar) - l;
			if (l[v] == tar) {
				flag = true;
				printf("yes %d %d\n", l[i], tar);
			}

		}

		if (!flag)printf("danger\n");

	}

}