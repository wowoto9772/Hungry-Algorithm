#include <stdio.h>
#include <string>

using namespace std;

int c[53];
string dp[53];
char *dig = "0123456789";

int main() {

	int n;
	while (scanf("%d", &n) == 1) {

		for (int i = 0; i < n; i++)scanf("%d", &c[i]);

		int m;
		scanf("%d", &m);

		for (int i = 0; i <= m; i++)dp[i] = "";

		string out = "";

		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j + c[i] <= m; j++) {
				if (dp[j + c[i]] == ""
					|| dp[j + c[i]].size() < dp[j].size() + 1
					|| dp[j + c[i]].size() == dp[j].size() + 1 && dp[j + c[i]] < (dp[j] + dig[i])) {
					if (i == 0 && dp[j][0] == '0')continue;
					dp[j + c[i]] = dp[j] + dig[i];
				}
			}
		}

		for (int i = 1; i <= m; i++) {
			if (out == "" || out.size() == dp[i].size() && out < dp[i]) {
				out = dp[i];
			}else if(out.size() < dp[i].size()){
				out = dp[i];
			}
		}

		printf("%s\n", out.c_str());

	}

}