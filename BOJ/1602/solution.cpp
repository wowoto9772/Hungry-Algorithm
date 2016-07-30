//#include <stdio.h>
//#include <set>
//#include <limits.h>
//#include <vector>
//
//#include <algorithm>
//
//using namespace std;
//
//class ele {
//public:
//	int v, p;
//	ele() {}
//	ele(int a, int b) { v = a, p = b; }
//	bool operator<(const ele &A)const {
//		return p > A.p;
//	}
//};
//
//int d[505][505];
//
//set <int> p[505][505];
//
//int main() {
//
//	int n, m, q;
//	scanf("%d %d %d", &n, &m, &q);
//
//	vector <ele> mid;
//
//	for (int i = 1; i <= n; i++) {
//
//		int a;
//		scanf("%d", &a);
//
//		for (int j = 1; j <= n; j++) {
//			d[i][j] = INT_MAX;
//		}
//
//		d[i][i] = a;
//		p[i][i].insert(a);
//
//		mid.emplace_back(i, a);
//	}
//
//	sort(mid.begin(), mid.end());
//
//	for (int i = 1; i <= m; i++) {
//		int a, b, c;
//		scanf("%d %d %d", &a, &b, &c);
//
//		for (auto &x : p[a][a]) {
//			for (auto &y : p[b][b]) {
//				int z = max(x, y);
//				if (d[a][b] > c + z) {
//					d[a][b] = d[b][a] = c + z;
//					p[a][b].insert(z);
//					p[b][a].insert(z);
//				}
//			}
//		}
//
//	}
//
//	for (int x = n-1; x >= 0; x--) {
//
//		int k = mid[x].v; // small to big
//
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (d[i][k] == INT_MAX || d[k][j] == INT_MAX)continue;
//				for (auto &a : p[i][k]) {
//					for (auto &b : p[k][j]) {
//						int z = max(a, b);
//						int c = d[i][k] - a + d[k][j] - b + z;
//						if (d[i][j] > c) {
//							d[i][j] = c;
//							p[i][j].clear();
//							p[i][j].insert(z);
//						}
//						else if (d[i][j] == c) {
//							p[i][j].insert(z);
//						}
//					}
//				}
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)if (d[i][j] == INT_MAX)d[i][j] = -1;
//
//	for (int i = 1; i <= q; i++) {
//		int a, b;
//		scanf("%d %d", &a, &b);
//
//		printf("%d\n", d[a][b]);
//	}
//}
//
///*
//4 4 1
//5 5 20 15
//1 4 1
//4 2 4
//1 2 10
//2 3 5
//1 3
//(30)
//*/

#include <stdio.h>
#include <limits.h>
#include <vector>

#include <algorithm>

using namespace std;

class ele {
public:
	int v, p;
	ele() {}
	ele(int a, int b) { v = a, p = b; }
	bool operator<(const ele &A)const {
		return p > A.p;
	}
};

int d[505][505];
int p[505][505];

int main() {

	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);

	vector <ele> mid;

	for (int i = 1; i <= n; i++) {

		int a;
		scanf("%d", &a);

		for (int j = 1; j <= n; j++) {
			d[i][j] = INT_MAX;
		}

		d[i][i] = a;
		p[i][i] = a;

		mid.emplace_back(i, a);
	}

	sort(mid.begin(), mid.end());

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		int z = max(p[a][a], p[b][b]);
		if (d[a][b] > c + z) {
			d[a][b] = d[b][a] = c + z;
			p[a][b] = p[b][a] = z;
		}

	}

	for (int x = n - 1; x >= 0; x--) {

		int k = mid[x].v; // small to big

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] == INT_MAX || d[k][j] == INT_MAX)continue;
				int z = max(p[i][k], p[k][j]);
				int c = d[i][k] - p[i][k] + d[k][j] - p[k][j] + z;
				if (d[i][j] > c) {
					d[i][j] = c;
					p[i][j] = z;
				}
				else if (d[i][j] == c) {
					if (p[i][j] < z)p[i][j] = z;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)if (d[i][j] == INT_MAX)d[i][j] = -1;

	for (int i = 1; i <= q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", d[a][b]);
	}
}

/*
4 4 1
5 5 20 15
1 4 1
4 2 4
1 2 10
2 3 5
1 3
(30)
*/