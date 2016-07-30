#include <stdio.h>
#include <algorithm>

using namespace std;

class ele {
public:
	ele() {}
	ele(int a, int b) { x = a, y = b; }
	int x, y;
}I[100003];

bool sort_x;

bool cmp(const ele &a, const ele &b) {
	if (sort_x) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &I[i].x, &I[i].y);
	}

	sort_x = true;
	sort(I, I + n, cmp);

	int ans = 0;

	for (int i = 0; i < n-1; i++) {
		if (I[i].x == I[i + 1].x) {
			ans++;
			while (i < n - 1 && I[i].x == I[i + 1].x) {
				i++;
			}
		}
	}

	sort_x = false;
	sort(I, I + n, cmp);

	for (int i = 0; i < n - 1; i++) {
		if (I[i].y == I[i + 1].y) {
			ans++;
			while (i < n - 1 && I[i].y == I[i + 1].y) {
				i++;
			}
		}
	}

	printf("%d\n", ans);

}