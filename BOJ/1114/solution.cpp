//#include <stdio.h>
//#include <limits.h>
//#include <algorithm>
//
//using namespace std;
//
//int p[10005];
//
//int L, K, C;
//
//bool pos;
//
//int find(int cur, int val) {
//
//	int l = cur + 1, r = K, m;
//	int cmp = val;
//
//	while (l <= r) {
//
//		m = (l + r) / 2;
//
//		if (p[m] >= val)r = m - 1;
//		else
//			l = m + 1;
//	}
//
//	while (m < K && p[m] < val)m++;
//	while (m > cur && p[m] > val)m--;
//
//	return m;
//}
//
//int main() {
//	scanf("%d %d %d", &L, &K, &C);
//
//	for (int i = 1; i <= K; i++) {
//		scanf("%d", &p[i]);
//	}
//
//	p[++K] = L;
//
//	sort(p, p + K + 1);
//
//	int l = 1, r = 1000000000, lim;
//
//	int ans = INT_MAX;
//
//	while (l <= r) {
//
//		lim = (l + r) / 2;
//
//		int c = 0;
//
//		bool flag = false;
//
//		int m = 0;
//		while (c < K && !flag) {
//			int nxt = find(c, p[c] + lim);
//			m++;
//			if (nxt == c)flag = true;
//			else {
//				c = find(c, p[c] + lim);
//			}
//		}
//
//		if (!flag && m <= C + 1) {
//			r = lim - 1;
//			if (ans > lim)ans = lim;
//		}
//		else
//			l = lim + 1;
//	}
//
//	for (int i = 1; i <= K; i++) {
//
//		if (p[i] <= ans) {
//
//			int c = i;
//
//			bool flag = false;
//
//			int m = 1;
//
//			while (c < K && !flag && m <= C + 1) {
//				int nxt = find(c, p[c] + ans);
//				m++;
//				if (nxt == c)flag = true;
//				else {
//					c = find(c, p[c] + ans);
//				}
//			}
//
//			if (!flag && m <= C + 1) {
//				printf("%d %d\n", ans, p[i]);
//				break;
//			}
//
//		}
//	}
//}

#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int p[10005];

int main() {

	int L, K, C;
	scanf("%d %d %d", &L, &K, &C);

	for (int i = 1; i <= K; i++) {
		scanf("%d", &p[i]);
	}

	p[++K] = L;

	sort(p, p + K + 1);

	int l = 1, r = 1000000000, lim;

	int ans = INT_MAX;

	while (l <= r) {

		lim = (l + r) / 2;

		int cnt = 0, stp = 0;

		for (int i = K - 1; i >= 0; i--) {
			stp += p[i + 1] - p[i];
			if (stp > lim) {
				cnt++;
				stp = p[i + 1] - p[i];
				if (stp > lim) {
					cnt = C + 1;
					break;
				}
			}
		}

		if (cnt <= C) {
			r = lim - 1;
			if (ans > lim)ans = lim;
		}
		else
			l = lim + 1;
	}

	int cnt = 0;
	int stp = 0;
	int le = K;

	for (int i = K - 1; i >= 0; i--) {
		stp += p[i + 1] - p[i];
		if (stp > ans) {
			cnt++;
			stp = p[i + 1] - p[i];
			le = i + 1;
		}
	}

	if (cnt < C)le = 1;

	printf("%d %d\n", ans, p[le]);
}