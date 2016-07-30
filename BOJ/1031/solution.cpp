//#include <stdio.h>
//#include <memory.h>
//#include <limits.h>
//
//#sinclude <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int cap[103][103];
//int flow[103][103];
//int pre[103];
//
//int fordFulkerson(int s, int t) {
//	
//	memset(flow, 0, sizeof(flow));
//
//	int m_flow = 0; // maximum flow
//
//	while (true) {
//		memset(pre, 0xff, sizeof(pre));
//
//		queue <int> q;
//		pre[s] = -2;
//		q.push(s);
//
//		while (!q.empty() && pre[t] == -1) {
//			int u = q.front();
//			q.pop();
//
//			for (int v = 1; v <= t; v++) {
//				if (pre[v] == -1) { // not seen yet
//					if (flow[v][u] || flow[u][v] < cap[u][v]) {
//						pre[v] = u; // v's previous node is u
//						q.push(v);
//					}
//				}
//			}
//		}
//
//		if (pre[t] == -1)break; // couldn't find any path to t(sink)
//
//		int bot = INT_MAX;
//		for (int v = t, u = pre[v]; u >= 0; v = u, u = pre[v]) {
//			if (flow[v][u]) // always use backward edge over forward
//				bot = min(bot, flow[v][u]);
//			else // must be a forwad edge otherwise
//				bot = min(bot, cap[u][v] - flow[u][v]);
//		}
//
//		for (int v = t, u = pre[v]; u >= 0; v = u, u = pre[v]) {
//			if (flow[v][u]) // backward edge
//				flow[v][u] -= bot;
//			else // forward edge
//				flow[u][v] += bot;
//		}
//
//		m_flow += bot;
//	}
//	return m_flow;
//}
//
//int row[55], col[55];
//
//#define src (0)
//#define snk (r+c+1)
//
//int main() {
//
//	int r, c;
//	scanf("%d %d", &r, &c);
//
//	int flg = 0;
//	for (int i = 1; i <= r; i++) {
//		scanf("%d", &row[i]);
//		flg += row[i];
//	}
//
//	for (int i = 1; i <= c; i++) {
//		scanf("%d", &col[i]);
//		flg -= col[i];
//	}
//
//	if (flg)printf("-1\n");
//	else {
//
//		for (int i = 1; i <= r; i++) {
//			for (int j = 1; j <= c; j++) {
//				cap[i][r + j] = 1;
//			}
//		}
//
//		for (int i = 1; i <= r; i++) {
//			cap[src][i] = row[i];
//			flg += row[i];
//		}
//		for (int i = 1; i <= c; i++)cap[r + i][snk] = col[i];
//
//		if (fordFulkerson(src, snk) != flg)printf("-1\n");
//		else {
//
//			for (int i = 1; i <= r; i++) {
//				for (int j = 1; j <= c; j++) {
//					bool flag = false;
//					if (!cap[i][r+j]) {
//						cap[src][i]++;
//						cap[r + j][snk]++;
//						cap[i][r + j] = 1;
//						if (fordFulkerson(src, snk) != flg) {
//							flag = true;
//							cap[src][i]--;
//							cap[r + j][snk]--;
//							cap[i][r + j] = 0;
//						}
//					}
//					printf("%d", 0 + (flag ? 1 : 0));
//				}printf("\n");
//			}
//
//		}
//
//	}
//
//
//
//}

#include <stdio.h>
#include <memory.h>

bool chk[103];
int cap[103][103];
int row[55], col[55];

int r, c;
#define src (0)
#define snk (r+c+1)

int dfs(int x) {

	if (chk[x])return 0;
	chk[x] = true;

	if (x == snk)return true;

	for (int i = src; i <= snk; i++) {
		if (cap[x][i] > 0) {
			if (dfs(i)) {
				cap[x][i]--;
				cap[i][x]++;
				return true;
			}
		}
	}

	return false;

}

int flow() {

	int ans = 0;

	while (true) {

		memset(chk, 0, sizeof(chk));

		if (!dfs(src)) {
			return ans;
		}

		ans++;
	}

}

int main() {

	scanf("%d %d", &r, &c);

	int flg = 0;
	for (int i = 1; i <= r; i++) {
		scanf("%d", &row[i]);
		flg += row[i];
	}

	for (int i = 1; i <= c; i++) {
		scanf("%d", &col[i]);
		flg -= col[i];
	}

	if (flg)printf("-1\n");
	else {

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cap[i][r + j] = 1;
			}
		}

		for (int i = 1; i <= r; i++) {
			cap[src][i] = row[i];
			flg += row[i];
		}
		for (int i = 1; i <= c; i++) {
			cap[r + i][snk] = col[i];
		}

		if (flow() != flg)printf("-1\n");
		else {

			for (int i = 1; i <= r; i++) {
				for (int j = 1; j <= c; j++) {
					bool flag = false;
					if (!cap[i][r + j]) {
						cap[src][i]++;
						cap[r + j][snk]++;

						memset(chk, 0, sizeof(chk));

						if (!dfs(src)) {
							flag = true;
							cap[src][i]--;
							cap[r + j][snk]--;
						}
					}

					cap[i][r + j] = 0;

					printf("%d", flag);
				}printf("\n");
			}

		}

	}



}