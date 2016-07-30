#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

int s;
char str[50003];
string tar;

int dp[50003];

vector <string> wrd['z' + 3];

int dy(int c) {

	if (c == s)return 1;
	if (dp[c] != -1)return dp[c];

	dp[c] = 0;

	for (int i = 0; i < wrd[str[c]].size() && !dp[c]; i++) {

		int a = wrd[str[c]][i].size();

		if (c + a <= s) {

			if (tar.substr(c, a) == wrd[str[c]][i]) {

				dp[c] = dy(c + a);

			}

		}

	}

	return dp[c];

}

int main() {

	vector <string> tot({ "h", "he",
		"li", "be", "b", "c", "n", "o", "f", "ne",
		"na", "mg", "al", "si", "p", "s", "cl", "ar",
		"k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr",
		"rb", "sr", "y", "zr", "nb", "mo",  "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe",
		"cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn",
		"fr", "ra", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv",
		"la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu",
		"ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr" });

	for (int i = 0; i < tot.size(); i++) {
		wrd[tot[i][0]].push_back(tot[i]);
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%s", str);

		tar = string(str);

		s = strlen(str);

		for (int i = 0; i < s; i++)dp[i] = -1;

		printf("%s\n", dy(0) ? "YES" : "NO");

	}

}