#include <stdio.h>
#include <set>

using namespace std;

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		multiset <int> v;

		int n;
		scanf("%d", &n);

		while (n--) {

			char x;
			int y;

			scanf(" %c %d", &x, &y);

			if (x == 'I')v.insert(y);
			else {

				if (v.empty())continue;

				if (y > 0) {
					multiset <int> ::iterator it = v.end();
					it--;

					v.erase(it);
				}
				else{
					v.erase(v.begin());
				}
			}

		}

		if (v.empty())printf("EMPTY\n");
		else {
			multiset <int> ::iterator it = v.end();
			it--;
			printf("%d %d\n", *it, *v.begin());
		}

	}

}