#include <stdio.h>
#include <string.h>
#include <map>

#define ll long long
#define mod 13000100000003067

using namespace std;

char str[1003];

int main() {

	scanf("%s", str);

	int s = strlen(str);

	map <ll, bool> chk;

	int ans = 0;

	for (int i = 1; i <= s; i++) {

		ll k = 0;
		ll x = 1;

		for (int j = 0; j < i; j++) {
			k = k * 26 + (str[j] - 'a' + 1);
			k %= mod;
			x *= 26LL;
			x %= mod;
		}

		if (!chk[k]) {
			chk[k] = true;
			ans++;
		}

		for (int j = i; j < s; j++) {
			k *= 26LL;
			k %= mod;
			k -= (x * (str[j - i] - 'a' + 1)) % mod;
			if (k < 0)k += mod;
			k += (str[j] - 'a' + 1);
			k %= mod;
			if (!chk[k]) {
				chk[k] = true;
				ans++;
			}
		}

	}

	printf("%d\n", ans);

}