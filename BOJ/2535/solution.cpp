#include <stdio.h>
#include <algorithm>

using namespace std;

class ele {
public:
	int c, i, s;
	bool operator<(const ele &A)const {
		return s < A.s;
	}
}I[103];

int c[103];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &I[i].c, &I[i].i, &I[i].s);
	}

	sort(I, I + n);
	
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (c[I[i].c] == 2)continue;

		ans++;

		c[I[i].c]++;

		printf("%d %d\n", I[i].c, I[i].i);

		if (ans == 3)break;
	}

}