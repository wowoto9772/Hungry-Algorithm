#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

char str[440];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	scanf("%s", str);

	int s = strlen(str);
	int f = 0;

	bool flag = false;

	vector <int> v;

	for (int i = 0; i < s; i++) {
		if (str[i] == ',' || i == s - 1) {
			if (i == s - 1)f = f * 10 + str[i] - '0';
			if (flag)f *= -1;
			flag = false;
			v.push_back(f);
			f = 0;
		}
		else {
			if (str[i] == '-') {
				flag = true;
			}
			else {
				f = f * 10 + str[i] - '0';
			}
		}
	}

	while (k--) {
		for (int i = 0; i < v.size() - 1; i++) {
			v[i] = v[i + 1] - v[i];
		}
		v.pop_back();
	}

	for (int i = 0; i < v.size(); i++) {
		if (i)printf(",");
		printf("%d", v[i]);
	}

}