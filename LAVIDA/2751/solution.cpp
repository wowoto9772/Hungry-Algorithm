//#include <stdio.h>
//#include <memory.h>
//#include <algorithm>
//
//#define MAX 1000000000
//
//using namespace std;
//
//int dp[1 << 20][2][2];
//
//int main() {
//
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	memset(dp, 0x4f, sizeof(dp));
//
//	dp[0][0][0] = 0;
//
//	for (int i = 0; i < m; i++) {
//
//		char a;
//		scanf(" %c", &a);
//
//		int spc = 0, swc = 0;
//
//		if (a == 'B')spc |= 1;
//
//		int c;
//		scanf("%d", &c);
//
//		for (int j = 1; j <= c; j++) {
//			int v;
//			scanf("%d", &v);
//			v--;
//			swc |= 1 << v;
//		}
//
//		int w = i & 1;
//
//		for (int j = 0; j < (1 << n); j++) {
//			for (int k = 0; k <= 1; k++) {
//
//				if (dp[j][k][w] >= MAX)continue;
//
//				dp[(j ^ swc)][k + spc][!w] = min(dp[(j ^ swc)][k + spc][!w], dp[j][k][w] + 1);
//				dp[j][k][!w] = min(dp[j][k][!w], dp[j][k][w]);
//
//			}
//		}
//
//	}
//
//	int x;
//	scanf("%d", &x);
//
//	for (int i = 1; i <= x; i++) {
//		int a;
//		scanf("%d", &a);
//
//		int g = 0;
//
//		for (int j = 1; j <= a; j++) {
//			int v;
//			scanf("%d", &v);
//
//			v--;
//
//			g |= 1 << v;
//		}
//
//		int x = min(dp[g][0][m&1], dp[g][1][m&1]);
//
//		if (x >= MAX)x = -1;
//
//		printf("%d\n", x);
//	}
//
//}

#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <queue>

#define MAX 1000000000

using namespace std;

class ele {
public:
	int s, n, v;
	ele() {}
	ele(int a, int b, int c) { s = a, n = b, v = c; }
	bool operator<(const ele &A)const {
		return v > A.v;
	}
};

int dp[1 << 20];
int spc[23], swc[23];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	memset(dp, 0x4f, sizeof(dp));

	dp[0] = 0;

	priority_queue <ele> q;

	for (int i = 0; i < m; i++) {

		char a;
		scanf(" %c", &a);

		if (a == 'B')spc[i] |= 1;

		int c;
		scanf("%d", &c);

		for (int j = 1; j <= c; j++) {
			int v;
			scanf("%d", &v);
			v--;
			swc[i] |= 1 << v;
		}

		dp[swc[i]] = 1;

		if(!spc[i])q.emplace(swc[i], 0, 1);
		else {
			q.emplace(swc[i], swc[i], 1);
		}

	}

	while (!q.empty()) {

		ele f = q.top(); q.pop();

		for (int i = 0; i < m; i++) {
			
			ele g = f;
			g.v++;

			if (spc[i]) {
				if (g.n & swc[i])continue;
				g.s ^= swc[i];
				g.n |= swc[i]; // fuck
			}
			else {
				g.s ^= swc[i];
			}
			
			if (dp[g.s] > g.v) {
				dp[g.s] = g.v;
				q.emplace(g);
			}
		}

	}

	for (int i = 0; i < (1 << n); i++)if (dp[i] >= MAX)dp[i] = -1;

	int x;
	scanf("%d", &x);

	for (int i = 1; i <= x; i++) {
		int a;
		scanf("%d", &a);

		int g = 0;

		for (int j = 1; j <= a; j++) {
			int v;
			scanf("%d", &v);

			v--;

			g |= 1 << v;
		}

		printf("%d\n", dp[g]);
	}

}