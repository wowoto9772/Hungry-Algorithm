#include <stdio.h>
#include <string>
#include <string.h>
#include <map>

#define ll long long

using namespace std;

string D[] = { "xxxxxx...xx...xx...xx...xx...xxxxxx", "....x....x....x....x....x....x....x", "xxxxx....x....xxxxxxx....x....xxxxx", "xxxxx....x....xxxxxx....x....xxxxxx", "x...xx...xx...xxxxxx....x....x....x", "xxxxxx....x....xxxxx....x....xxxxxx", "xxxxxx....x....xxxxxx...xx...xxxxxx","xxxxx....x....x....x....x....x....x", "xxxxxx...xx...xxxxxxx...xx...xxxxxx", "xxxxxx...xx...xxxxxx....x....xxxxxx" };

char str[8][203];
char out[8][203];

ll ten(int k) { // 10^k

	ll ret = 1;
	for (int i = 1; i <= k; i++) {
		ret *= 10LL;
	}

	return ret;

}

int sze(ll v) {
	if (!v)return 1;
	int ret = 0;
	while (v) {
		ret++;
		v /= 10;
	}return ret;
}

int main() {

	map <string, int> dig;

	for (int i = 0; i < 10; i++)dig[D[i]] = 1 + i;

	for (int i = 0; i < 7; i++)scanf("%s", str[i]);

	ll v = 0;

	int s = strlen(str[0]);

	ll u = 0;

	for (int i = 0; i < s; i++) {
		string x;
		for (int j = 0; j < 7; j++) {
			for (int k = i; k <= i + 4; k++) {
				x += str[j][k];
			}
		}
		if (dig[x]) {
			v = v * 10LL + (dig[x] - 1);
		}
		else {
			// +
			u = v;
			v = 0;
		}
		i += 5;
	}

	u += v;

	s = sze(u);

	int t = s - 1;

	for (int i = 0; i < s; i++) {

		int g = u / ten(t);
		int tp = 0;

		for (int j = 0; j < 7; j++) {
			for (int k = 6 * i; k <= 6 * i + 4; k++) {
				out[j][k] = D[g][tp++];
			}
			if (i < s - 1)out[j][6 * i + 5] = '.';
		}
		u -= u / ten(t) * ten(t);
		t--;
	}

	for (int i = 0; i < 7; i++)printf("%s\n", out[i]);

}