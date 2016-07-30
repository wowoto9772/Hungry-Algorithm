//#include <stdio.h>
//#include <memory.h>
//
//#define L 100
//
//char dp[L + 3][L + 3][L + 3];
//char val[L + 3][L + 3][L + 3];
//char spl[L + 3][L + 3][L + 3];
//
//char dy(int le, int ri, int v) {
//
//	if (dp[le][ri][v] != -1)return dp[le][ri][v];
//
//	dp[le][ri][v] = 0;
//
//	for (int x = 0; x <= L - v; x++) {
//
//		for (int i = le; i < ri; i++) {
//
//			if (dy(le, i, x) && dy(i + 1, ri, x + v) ||
//				dy(le, i, x + v) && dy(i + 1, ri, x)) {
//
//				spl[le][ri][v] = i;
//				val[le][ri][v] = x;
//
//				return dp[le][ri][v] = 1;
//
//			}
//
//		}
//
//	}
//
//	return dp[le][ri][v];
//
//}
//
//void print(int le, int ri, int v, int x) {
//
//	if (le < ri) {
//
//		int u = val[le][ri][v];
//		int k = spl[le][ri][v];
//
//		if (dp[le][k][u] && dp[k + 1][ri][u + v]) {
//			print(le, k, u, x);
//			printf("%d\n", x);
//			print(k + 1, ri, u + v, x + 1);
//		}
//		else {
//			print(le, k, u + v, x);
//			printf("%d\n", x);
//			print(k + 1, ri, u, x + 1);
//		}
//
//	}
//
//}
//
//int main() {
//
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	memset(dp, 0xff, sizeof(dp));
//
//	for (int i = 1; i <= n; i++) {
//
//		int a;
//		scanf("%d", &a);
//
//		dp[i][i][a] = 1;
//		val[i][i][a] = a;
//		spl[i][i][a] = i;
//
//	}
//
//	if (!dy(1, n, m))printf("0\n");
//	else {
//
//		print(1, n, m, 1);
//
//	}
//
//}

#include <stdio.h>
#include <map>

using namespace std;

map < int, map <int, int> > dp;

int e[104];
int n, t;

int dy(int s, int i) {

	if (i == n + 1) {
		if(s == t)return 1;
		return 0;
	}

	if (dp[s].find(i) != dp[s].end())return dp[s][i];

	dp[s][i] = 0;

	dp[s][i] = dy(s - e[i], i + 1);
	
	if (!dp[s][i]) {
		dp[s][i] = dy(s + e[i], i + 1);
	}

	return dp[s][i];

}

void swp(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int main() {

	scanf("%d %d", &n, &t);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &e[i]);
	}

	if (n == 1) {}
	else if (n <= 2)printf("1\n");
	else {

		dy(e[1] - e[2], 3);

		int s = e[1] - e[2], a = 3;
		int top = 1;

		int ans[103] = { 1 };

		while (a <= n) {

			if (dy(s + e[a], a + 1)) {
				ans[top++] = 2;
				s += e[a];
				a++;
			}
			else {
				ans[top++] = 1; // -
				s -= e[a];
				a++;
			}

		}

		for (int i = 0; i < top; i++) {
			if (i+1 < top && ans[i + 1] == 2) {
				for (int j = i + 1; j < top; j++) {
					if (ans[j] != 2) {
						swp(ans[i], ans[j - 1]);
						i = j - 1;
						break;
					}
					else if (j == top - 1) {
						swp(ans[i], ans[j]);
						i = j;
						break;
					}
				}
			}
			else {
				continue;
			}
		}

		for (int i = 0; i < top; i++)printf("%d\n", ans[i]);

	}

}