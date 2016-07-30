#include <stdio.h>
#include <algorithm>

using namespace std;

char str[5];
int fail[103][17];
bool solv[103][17];

class ele {
public:
	int ind, pen, sol;
	bool operator<(const ele &A)const {
		if (sol == A.sol) {
			if (pen == A.pen)return ind < A.ind;
			return pen < A.pen;
		}
		return sol > A.sol;
	}
}I[103];

void swp(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int main() {

	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);

	for (int i = 1; i <= n; i++)I[i].ind = i;

	for (int i = 1; i <= q; i++) {

		int x, y, z;
		scanf("%d %d %d %s", &x, &y, &z, &str);

		if (!solv[y][z]) {
			if (str[0] == 'A')solv[y][z] = true, I[y].sol++, I[y].pen += fail[y][z] * 20 + x;
			else
				fail[y][z]++;
		}

	}

	sort(I + 1, I + 1 + n);

	for (int i = 1; i <= n; i++)printf("%d %d %d\n", I[i].ind, I[i].sol, I[i].pen);

}