#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int tc = 0;
	int p, e, i, d;
	while (scanf("%d %d %d %d", &p, &e, &i, &d) == 4) {

		if (p == e && e == i && i == d && i == -1)break;

		while (1) {
			if (p == e && e == i && p > d) {
				break;
			}
			int mi = min({ p, e, i });
			if (mi == p)p += 23;
			else if (mi == e)e += 28;
			else if (mi == i)i += 33;
		}

		printf("Case %d: the next triple peak occurs in ", ++tc);

		p -= d;
		if (p > 21252)p -= 21252;
		printf("%d days.\n", p);
	}
	return 0;
}