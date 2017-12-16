#include <cstdio>
#include <cstring>
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

int main()
{

	scanf("%s %s", str[0], str[1]);

	int le = strlen(str[0]);
	int ri = strlen(str[1]);
    
    for(int i=0; i<le; i++)S[1+i] = str[0][i];
    S[le+1] = '#';
    for(int i=0; i<ri; i++)S[le+2+i] = str[1][i];

	N = strlen(S + 1);
	SuffixArray(); LCP();

	int ans = -1;
	int p;

	for (int i = 2; i <= N; i++) {
		if (ans < lcp[i]) {
			if (SA[i-1] > le+1 && SA[i] > le+1)continue; // only second two string
			if (SA[i-1] < le+1 && SA[i] < le+1)continue; // only first two string
			ans = lcp[i];
			p = SA[i];
		}
	}

	printf("%d\n", ans);

	for (int i = p; ans; i++) {
		printf("%c", S[i]);
		ans--;
	}

} 