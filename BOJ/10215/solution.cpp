#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

#define fnd(a, b) (E[a][b] == 0)

using namespace std;

int cmd[18];
int n;

int thr[16] = { 1 };

int dr['T' + 3];
int dc['T' + 3];

map < int, map < int, double > > dp;

vector < vector <int> > hashs(int v) {

	vector < vector <int> > S;

	S.resize(4);

	for (int i = 15; i >= 0; i--) {
		S[i / 4].push_back(v / thr[i]);
		v -= (v / thr[i]) * thr[i];
	}

	for (int i = 0; i < 4; i++)reverse(S[i].begin(), S[i].end());

	return S;

}

int unhashs(vector < vector <int> > S) {

	int X = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			X += thr[i * 4 + j] * S[i][j];
		}
	}

	return X;

}

double dy(int c, int S) {

	if (dp[c].find(S) != dp[c].end())return dp[c][S];

	vector < vector <int> > E = hashs(S);

	dp[c][S] = 0.0;

	if (n != c) {

		if (cmd[c] == 'W' || cmd[c] == 'G') {

			int x = (cmd[c] == 'W') ? 1 : 2;

			int spc = (fnd(1, 1) + fnd(1, 2) + fnd(2, 1) + fnd(2, 2));

			if (spc == 0) {
				spc += (fnd(0, 0) + fnd(0, 1) + fnd(0, 2) + fnd(0, 3) +
					fnd(3, 0) + fnd(3, 1) + fnd(3, 2) + fnd(3, 3) +
					fnd(1, 0) + fnd(2, 0) + fnd(1, 3) + fnd(2, 3));

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (E[i][j])continue;
						E[i][j] = x;
						dp[c][S] += dy(c + 1, unhashs(E)) / spc;
						E[i][j] = 0;
					}
				}
			}
			else {

				if (spc != 3) {
					for (int i = 1; i <= 2; i++) {
						for (int j = 1; j <= 2; j++) {
							if (!E[i][j]) {
								E[i][j] = x;
								dp[c][S] += dy(c + 1, unhashs(E)) / spc;
								E[i][j] = 0;
							}
						}
					}
				}
				else {
					if (E[1][1]) {
						E[2][2] = x;
						dp[c][S] += dy(c + 1, unhashs(E));
						E[2][2] = 0;
					}
					else if (E[1][2]) {
						E[2][1] = x;
						dp[c][S] += dy(c + 1, unhashs(E));
						E[2][1] = 0;
					}
					else if (E[2][1]) {
						E[1][2] = x;
						dp[c][S] += dy(c + 1, unhashs(E));
						E[1][2] = 0;
					}
					else {
						E[1][1] = x;
						dp[c][S] += dy(c + 1, unhashs(E));
						E[1][1] = 0;
					}
				}

			}


		}
		else {

			int cd = cmd[c];

			for (int k = 0; k < 4; k++) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						int ni = i + dr[cd];
						int nj = j + dc[cd];

						if (ni < 0 || ni >= 4 || nj < 0 || nj >= 4)continue;
						if (!E[ni][nj] && E[i][j]) {
							E[ni][nj] = E[i][j];
							E[i][j] = 0;
						}
					}
				}
			}

			dp[c][S] += dy(c + 1, unhashs(E));
		}

	}

	return dp[c][S];

}

char str[6];

int main() {

	for (int i = 1; i <= 15; i++)thr[i] = thr[i - 1] * 3;

	dr['L'] = 0, dc['L'] = -1;
	dr['R'] = 0, dc['R'] = 1;
	dr['T'] = -1, dc['T'] = 0;
	dr['B'] = 1, dc['B'] = 0;

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf(" %c", &cmd[i]);
		}

		vector < vector <int> > g;
		g.resize(4);

		int goal = 0;

		for (int i = 0; i < 4; i++) {
			scanf("%s", str);
			for (int j = 0; j < 4; j++) {
				if (str[j] == 'W')goal += thr[i * 4 + j] * 1;
				else if (str[j] == 'G')goal += thr[i * 4 + j] * 2;
			}
		}

		dp[n][goal] = 1.0;

		printf("%.9lf\n", dy(0, 0));

		dp.clear();

	}

}