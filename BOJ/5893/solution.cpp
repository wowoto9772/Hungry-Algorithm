#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

char str[1003];
int g[1003];

int main() {

	scanf("%s", str);

	int s = strlen(str);

	for (int i = s - 1; i >= 0; i--) {
		g[i] = (str[i] - '0') * 17;
	}

	string ans;
	for (int i = s - 1; i >= 1; i--) {
		g[i - 1] += g[i] / 2;
		g[i] %= 2;
		char tmp = g[i] + '0';
		ans = tmp + ans;
	}

	while (g[0]) {
		int k = g[0] / 2;
		g[0] %= 2;
		char tmp = g[0] + '0';
		ans = tmp + ans;
		g[0] = k;
	}

	printf("%s\n", ans.c_str());

}