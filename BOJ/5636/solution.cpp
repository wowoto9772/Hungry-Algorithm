#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

bool isPrime(int v) {
	if (v == 2)return true;
	else if (!(v%2) || v < 2)return false;
	else {

		for (int i = 3; i*i <= v; i += 2) {
			if (v%i)continue;
			return false;
		}

		return true;
	}
}

int toInt(string v) {
	int ret = 0;
	for (int i = 0; i < v.size(); i++)ret = ret * 10 + v[i] - '0';
	return ret;
}

char st[259];

int main() {

	while (scanf("%s", st) == 1) {

		string str = string(st);

		if (str.compare("0") == 0)break;

		int s = str.size();

		int ans = 0;

		for (int k = 6; k >= 1; k--) {
			for (int i = 0; i + k < s; i++) {
				
				string tmp = str.substr(i, k);
				int v = toInt(tmp);

				if (v > 100000)continue;

				if (isPrime(v)) {
					ans = max(ans, v);
				}

			}
		}

		printf("%d\n", ans);

	}

}