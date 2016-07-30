#include <stdio.h>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//map < vector < pair <int, int> >, map < int , int > > dp;
//
//int dy(vector < pair <int, int> > sets, int k) {
//
//	if (dp[sets].find(k) != dp[sets].end())return dp[sets][k];
//
//	dp[sets][k] = !k;
//
//	for (int i = 0; i < sets.size() && dp[sets][k] != k; i++) {
//
//		if (k) {
//
//			// horizontal (height)
//
//			if (sets[i].second > 1) {
//
//				for (int j = 1; j <= sets[i].second / 2 && dp[sets][k] != k; j++) {
//
//					vector < pair <int, int> > nxts = sets;
//
//					int rem = nxts[i].second - j;
//					nxts[i].second = j;
//					if (nxts[i].first == 1 && rem == 1) {}
//					else {
//						nxts.push_back(make_pair(nxts[i].first, rem));
//					}
//					if (nxts[i].second == 1 && nxts[i].first == 1) {
//						nxts.erase(nxts.begin() + i);
//					}
//
//					sort(nxts.begin(), nxts.end());
//
//					dp[sets][k] = dy(nxts, !k);
//
//				}
//
//			}
//
//		}
//		else {
//
//			// vertical (width)
//
//			if (sets[i].first > 1) {
//
//				for (int j = 1; j <= sets[i].first / 2 && dp[sets][k] != k; j++) {
//
//					vector < pair <int, int> > nxts = sets;
//
//					int rem = nxts[i].first - j;
//					nxts[i].first = j;
//					if (nxts[i].second == 1 && rem == 1) {}
//					else {
//						nxts.push_back(make_pair(rem, nxts[i].second));
//					}
//
//					if (nxts[i].second == 1 && nxts[i].first == 1) {
//						nxts.erase(nxts.begin() + i);
//					}
//
//					sort(nxts.begin(), nxts.end());
//
//					dp[sets][k] = dy(nxts, !k);
//
//				}
//
//			}
//
//
//		}
//
//	}
//
//	return dp[sets][k];
//
//}

int dp[505][505][2];
char x[8];

int main() {

	//vector < pair<int, int> > x;
	//x.push_back(make_pair(0, 0));

	// second : height
	// first : width

	//for (int w = 1; w <= 8; w++) {
	//	for (int h = 1; h <= 8; h++) {
	//		if (h > 1)printf(" ");
	//		x[0].first = w, x[0].second = h;
	//		dp.clear();
	//		printf("%d", dy(x, 1)); // horizontal harry
	//		dp.clear();
	//		printf("(%d)", dy(x, 0)); // verical vicky
	//	}printf("\n");
	//}

	int dh = 1;
	int c = dh;

	for (int w = 1; w <= 500; w++) {
		for (int h = 1; h <= 500; h++) {
			if ((dh * 2) <= h)dp[w][h][1] = 1;
			if (dh <= h)dp[w][h][0] = 1;
		}
		c--;
		if (!c) {
			dh <<= 1;
			if (dh > 500)dh = 500;
			c = dh;
		}
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		int w, h;

		scanf("%d %d", &w, &h);

		scanf("%s", &x);

		if (x[0] == 'H') {
			x[0] = 1;
			printf("Harry ");
		}
		else {
			x[0] = 0;
			printf("Vicky ");
		}

		printf("%s\n", (dp[w][h][x[0]] == x[0]) ? "can win" : "cannot win");

	}

}