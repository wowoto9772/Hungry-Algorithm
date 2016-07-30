#include <stdio.h>
#include <string.h>

#include <string>
#include <vector>

#include <algorithm>

using namespace std;

vector <string> wrd;

string s;

string dp[1001];

int m, n, l;

bool can(string a, string b) {
	// is possible that A consists of B
	int s = b.size();
	for (int i = 0; i < s; i++)if (a[i] != b[i] && a[i] != '?')return false;
	return true;
}

string dy(int c) {
	if (c == m)return "";
	if (dp[c] != "")return dp[c];

	for (int i = 0; i < l; i++) {
		int k = wrd[i].size();
		if (c + k <= m) {
			string a = s.substr(c, k);
			if (can(a, wrd[i])) {
				if (dp[c] == "")dp[c] = wrd[i] + dy(c + k);
				else {
					string tmp = dp[c];
					dp[c] = wrd[i] + dy(c + k);
					if (dp[c].size() != m - c)dp[c] = tmp;
					else {
						if (tmp.size() == m - c) {
							if (tmp < dp[c])dp[c] = tmp;
						}
					}
				}
			}
		}
	}return dp[c];
}

char str[1003];

int main()
{
	scanf("%d %d", &m, &n);

	scanf("%s", str);

	s = string(str);

	string a;

	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		wrd.push_back(string(str));
	}

	sort(wrd.begin(), wrd.end());

	l = wrd.size();

	printf("%s\n", dy(0).c_str());
}