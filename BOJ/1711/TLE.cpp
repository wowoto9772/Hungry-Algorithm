#include <stdio.h>
#include <vector>
#include <algorithm>

#define x first
#define y second

using namespace std;

#define ll long long

bool orthogonal(ll dx, ll dy, ll dx2, ll dy2) {
	return (dx*dx2 + dy*dy2 == 0LL);
}

pair <int, int> e[1503];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &e[i].x, &e[i].y);
	}

	sort(e, e + n);

//	for (int i = 0; i < n; i++)printf("%d,%d\n", e[i].x, e[i].y);

	int c = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				// ij jk
				// ik kj
				// ji ik
				if (orthogonal(e[i].x - e[j].x, e[i].y - e[j].y, e[j].x - e[k].x, e[j].y - e[k].y)) {
//					printf("%d-%d-%d\n", i, j, k);
					c++;
				}
				else if (orthogonal(e[i].x - e[k].x, e[i].y - e[k].y, e[k].x - e[j].x, e[k].y - e[j].y)) {
//					printf("%d-%d-%d\n", i, k, j);
					c++;
				}else if(orthogonal(e[j].x - e[i].x, e[j].y - e[i].y, e[i].x - e[k].x, e[i].y - e[k].y)) {
//					printf("%d-%d-%d\n", j, i, k);
					c++;
				}
			}
		}
	}

	printf("%d\n", c);

}