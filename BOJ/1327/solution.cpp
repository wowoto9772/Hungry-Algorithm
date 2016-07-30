//#include <stdio.h>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//#define MAX 987654321
//
//map < vector <int>, int > dp;
//
//int k;
//
//void swp(int &a, int &b) {
//	int t = a;
//	a = b;
//	b = t;
//}
//
//int dy(vector <int> v) {
//	if (dp.find(v) != dp.end())return dp[v];
//
//	vector <int> ov = v;
//
//	bool end = true;
//	for (int i = 0; end && i < v.size() - 1; i++) {
//		if (v[i] > v[i+1]) {
//			end = false;
//		}
//	}
//
//	if (end)dp[v] = 0;
//	else {
//
//		dp[v] = MAX;
//
//		for (int i = 0; i <= v.size() - k; i++) {
//			for (int j = 0; j < k / 2; j++) {
//				swp(v[i + j], v[i + k - 1 - j]);
//			}
//			dp[ov] = min(dp[ov], 1 + dy(v));
//			for (int j = 0; j < k / 2; j++) {
//				swp(v[i + j], v[i + k - 1 - j]);
//			}
//		}
//
//	}
//
//	return dp[v];
//
//}
//
//int main() {
//
//	int n;
//	scanf("%d %d", &n, &k);
//
//	vector <int> a(n);
//
//	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
//
//	int d = dy(a);
//
//	if (d >= MAX) d = -1;
//
//	printf("%d\n", d);
//
//}

#include <stdio.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map < vector <int>, int > chk;

int k;

void swp(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int main() {

	int n;
	scanf("%d %d", &n, &k);

	vector <int> a(n);

	for (int i = 0; i < n; i++)scanf("%d", &a[i]);

	queue < vector<int> >  q;

	q.emplace(a);

	while (!q.empty()) {

		vector < int > v = q.front();
		q.pop();

		bool end = true;
		for (int i = 0; end && i < v.size() - 1; i++) {
			if (v[i] > v[i + 1]) {
				end = false;
			}
		}

		if (end) {
			printf("%d\n", chk[v]);
			return 0;
		}
		else {

			vector <int> ov = v;

			for (int i = 0; i <= v.size() - k; i++) {
				for (int j = 0; j < k / 2; j++) {
					swp(v[i + j], v[i + k - 1 - j]);
				}
				if (chk.find(v) == chk.end()) {
					chk[v] = chk[ov] + 1;
					q.emplace(v);
				}
				for (int j = 0; j < k / 2; j++) {
					swp(v[i + j], v[i + k - 1 - j]);
				}
			}

		}


	}

	printf("-1\n");

}