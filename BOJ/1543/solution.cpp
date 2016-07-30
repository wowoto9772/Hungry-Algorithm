#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

string org, tar;
char str[5003];

int main() {

	fgets(str, 5000, stdin);
	str[strlen(str) - 1] = 0;
	org = string(str);

	fgets(str, 100, stdin);
	str[strlen(str) - 1] = 0;
	tar = string(str);

	int s = org.size();
	int k = tar.size();

	int ans = 0;
	for (int i = 0; i + k - 1 < s; i++) {

		if (org.substr(i, k).compare(tar) == 0) {
			ans++;
			i += k - 1;
		}

	}

	printf("%d\n", ans);

}