#include <stdio.h>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

class ele {
public:
	int d, v;
	bool operator<(const ele &A)const {
		return v > A.v;
	}
}I[200003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &I[i].d, &I[i].v);
	}

	sort(I, I + n);

	ll c = 0;

	set <int> d;

	d.insert(0);
	for (int i = 1; i <= n; i++)d.insert(i);

	for (int i = 0; i < n; i++) {
		set <int> ::iterator it = d.lower_bound(I[i].d);
		if (*it == I[i].d) {
			d.erase(it);
			c += I[i].v;
		}
		else {
			if (it != d.begin())it--;
			if (*it > 0) {
				d.erase(it);
				c += I[i].v;
			}
		}
	}

	printf("%lld\n", c);

}