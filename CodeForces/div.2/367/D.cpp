#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {

	multiset <int> sexy;

	int n;
	scanf("%d", &n);

	sexy.insert(0);

	while (n--) {

		char t;
		int v;
		scanf(" %c %d", &t, &v);

		if (t == '+')sexy.insert(v);
		else if (t == '-') {

			multiset <int> ::iterator it = sexy.lower_bound(v);

			if (*it == v) {
				sexy.erase(it);
			}

		}
		else {

			int x = 0;

			for (int i = 30; i >= 0; i--) {

				int add = 0, spc = 0;

				if (v & (1 << i))spc = 1 << i;
				else
					add = 1 << i;

				multiset <int> ::iterator it = sexy.lower_bound(x | add);

				if (it != sexy.end() && ((*it) >> i) == ((x | add) >> i)) {
					// possible
					x |= add;
				}
				else {
					// impossible
					x |= spc;
				}

			}

			multiset <int> ::iterator e = sexy.lower_bound(x);

			printf("%d\n", *e ^ v);


		}

	}

}