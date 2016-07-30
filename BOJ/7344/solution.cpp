#include <stdio.h>

#include <algorithm>

using namespace std;

class ele {
public:
	int x, y;
	bool operator<(const ele &A)const {
		if (x == A.x)return y < A.y;
		return x < A.x;
	}
}I[5003];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)scanf("%d %d", &I[i].x, &I[i].y);

		sort(I + 1, I + 1 + n);

		bool chk[5003] = { 0 };

		int c = 0;

		for (int i = 1; i <= n; i++) {
			if (!chk[i]) {
				chk[i] = true;
				c++;

				int s = i;

				for (int j = i + 1; j <= n; j++) {
					if (!chk[j] && I[s].x <= I[j].x) {
						if (I[s].y <= I[j].y) {
							s = j;
							chk[j] = true;
						}
					}
				}
			}
		}

		printf("%d\n", c);
	}
}