#include <stdio.h>
#include <algorithm>

using namespace std;

class ele {
public:
	int l, r;
	bool operator<(const ele &A)const {
		if (r == A.r)return l < A.l;
		return r < A.r;
	}
}I[100003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &I[i].l, &I[i].r);
	}

	sort(I, I + n);

	int ans = 0, ri = 0;

	for (int i = 0; i < n; i++) {
		if (ri <= I[i].l) {
			ans++;
			ri = I[i].r;
		}
	}

	printf("%d\n", ans);

}

/*

	3
	3 3
	2 3
	1 3

	3
	1 3
	2 3
	3 3

*/