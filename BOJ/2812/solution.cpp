#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

char str[500003];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	scanf("%s", str);

	int s = strlen(str);

	vector <char> ans;
	ans.push_back(str[0]);

	for (int i = 1; i < s; i++) {
		while (k && !ans.empty() && ans.back() < str[i]) {
			k--;
			ans.pop_back();
		}
		ans.push_back(str[i]);
	}

	while (k) {
		k--;
		ans.pop_back();
	}

	for (int i = 0; i < ans.size(); i++)printf("%c", ans[i]);
	printf("\n");

}