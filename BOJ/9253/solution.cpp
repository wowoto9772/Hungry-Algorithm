#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 200005

int N;
int SA[MAXN], lcp[MAXN];
char S[MAXN];

void SuffixArray()
{
	int i, j, k;
	int m = 28;
	vector <int> cnt(max(N, m) + 1, 0), x(N + 1, 0), y(N + 1, 0);
	for (i = 1; i <= N; i++) {
		if (S[i] == '#') {
			x[i] = 27;
			cnt[x[i]]++;
		}
		else if (S[i] == '$') {
			x[i] = 28;
			cnt[x[i]]++;
		}
		else
			cnt[x[i] = S[i] - 'a' + 1]++;
	}
	for (i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
	for (i = N; i; i--) SA[cnt[x[i]]--] = i;

	for (int len = 1, p = 1; p < N; len <<= 1, m = p) {
		for (p = 0, i = N - len; ++i <= N;) y[++p] = i;
		for (i = 1; i <= N; i++) if (SA[i] > len) y[++p] = SA[i] - len;
		for (i = 0; i <= m; i++) cnt[i] = 0;
		for (i = 1; i <= N; i++) cnt[x[y[i]]]++;
		for (i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
		for (i = N; i; i--) SA[cnt[x[y[i]]]--] = y[i];
		swap(x, y); p = 1; x[SA[1]] = 1;
		for (i = 1; i < N; i++) {
			x[SA[i + 1]] = (SA[i] + len <= N && SA[i + 1] + len <= N && y[SA[i]] == y[SA[i + 1]] && y[SA[i] + len] == y[SA[i + 1] + len]) ? p : ++p;
		}
	}
}

void LCP()
{
	int i, j, k = 0;
	vector <int> rank(N + 1, 0);
	for (i = 1; i <= N; i++) rank[SA[i]] = i;
	for (i = 1; i <= N; lcp[rank[i++]] = k)
		for (k ? k-- : 0, j = SA[rank[i] - 1]; S[i + k] == S[j + k]; k++);
}

char str[2][200003];

char tmp[200003];

int main()
{

	scanf("%s %s", str[0], str[1]);

	int le = strlen(str[0]);
	int ri = strlen(str[1]);

	if (le < ri) {

		for (int i = 0; i < ri; i++)S[i + 1] = str[1][i];
		for (int i = 0; i < le; i++)S[i + ri + 1] = str[0][i];

		swap(le, ri);

	}
	else {

		for (int i = 0; i < le; i++)S[i + 1] = str[0][i];
		for (int i = 0; i < ri; i++)S[i + le + 1] = str[1][i];

	}

	N = strlen(S + 1);

	SuffixArray(); LCP();

	int ans = -1;
	int p;

	vector <int> cand;

	for (int i = 2; i <= N; i++) {
		if (ans < lcp[i]) {
			if (SA[i - 1] > le && SA[i] > le)continue; // only second two string
			if (SA[i - 1] <= le && SA[i] <= le)continue; // only first two string
			ans = lcp[i];
			p = SA[i];

			cand.clear();

			cand.push_back(SA[i]);
		}
		else if (ans == lcp[i]) {

			cand.push_back(SA[i]);

		}
	}

	scanf("%s", tmp);

	int s = strlen(tmp);

	if (s == ans) {

		string sexy = string(S + 1);
		string target = string(tmp);

		for (int i = 0; i < cand.size(); i++) {
			if (sexy.substr(cand[i] - 1, ans) == target) {
				printf("YES\n");
				return 0;
			}
		}

		printf("NO\n");

	}
	else {

		printf("NO\n");

	}

}