//#include <stdio.h>
//
//#include <queue>
//#include <vector>
//
//#include <algorithm>
//
//using namespace std;
//
//class ele {
//public:
//	int v, c;
//	ele() {}
//	ele(int a, int b) { v = a, c = b; }
//};
//
//int d[1003], r[1003];
//
//int main() {
//
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	if (n == 1) {
//		printf("0\n1\n");
//	}
//	else {
//
//		vector < vector <ele> > lnk;
//
//		lnk.resize(n + 1);
//
//		for (int i = 1; i <= m; i++) {
//
//			int a, b, c;
//			scanf("%d %d %d", &a, &b, &c);
//
//			lnk[a].emplace_back(b, c);
//
//		}
//
//		int fin = 0, fp;
//
//		queue <ele> q;
//		q.emplace(1, 0);
//
//		while (!q.empty()) {
//			ele f = q.front(); q.pop();
//			for (int j = 0; j < lnk[f.v].size(); j++) {
//				ele g = lnk[f.v][j];
//				if (g.v == 1) {
//					if (fin < f.c + g.c) {
//						fin = f.c + g.c;
//						fp = f.v;
//					}
//				}
//				else {
//					if (d[g.v] < f.c + g.c) {
//						d[g.v] = f.c + g.c;
//						r[g.v] = f.v;
//						g.c = d[g.v];
//						q.emplace(g);
//					}
//				}
//			}
//		}
//
//		vector <int> D;
//		while (fp) {
//			D.push_back(fp);
//			fp = r[fp];
//		}
//
//		reverse(D.begin(), D.end());
//
//		printf("%d\n", fin);
//
//		for (int i = 0; i < D.size(); i++)printf("%d ", D[i]);
//		printf("1\n");
//
//	}
//
//}
#include <stdio.h>

#include <queue>
#include <vector>

#include <algorithm>

using namespace std;

class ele {
public:
	int v, c;
	ele() {}
	ele(int a, int b) { v = a, c = b; }
};

int d[1003], r[1003];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	if (n == 1) {
		printf("0\n1\n");
	}
	else {

		int in[1003] = { 0 };

		vector < vector <ele> > lnk;

		lnk.resize(n + 1);

		for (int i = 1; i <= m; i++) {

			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);

			lnk[a].emplace_back(b, c);

			in[b]++;

		}

		int fin = 0, fp;

		queue <int> q;

		q.push(1);

		while (!q.empty()) {

			int f = q.front(); q.pop();

			for (int i = 0; i < lnk[f].size(); i++) {
				ele g = lnk[f][i];

				if (g.v == 1) {
					if (fin < d[f] + g.c) {
						fin = d[f] + g.c;
						fp = f;
					}
				}
				else {

					in[g.v]--;

					if (d[g.v] < g.c + d[f]) {
						d[g.v] = g.c + d[f];
						r[g.v] = f;
					}

					if (!in[g.v]) {
						q.push(g.v);
					}

				}
			}

		}

		vector <int> D;
		while (fp) {
			D.push_back(fp);
			fp = r[fp];
		}

		reverse(D.begin(), D.end());

		printf("%d\n", fin);

		for (int i = 0; i < D.size(); i++)printf("%d ", D[i]);
		printf("1\n");

	}

}