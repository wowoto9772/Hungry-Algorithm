#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int mp['Z' + 3];
char str[23];

int main() {

	mp['B'] = mp['F'] = mp['P'] = mp['V'] = '1';
	mp['C'] = mp['G'] = mp['J'] = mp['K'] = mp['Q'] = mp['S'] = mp['X'] = mp['Z'] = '2';
	mp['D'] = mp['T'] = '3';
	mp['L'] = '4';
	mp['M'] = mp['N'] = '5';
	mp['R'] = '6';

	while (scanf("%s", str) == 1) {

		int s = strlen(str);

		string out = "";
		int c = 0;

		for (int i = 0; i < s; i++) {

			if (mp[str[i]] && c != mp[str[i]]) {
				out += mp[str[i]];
			}

			c = mp[str[i]];

		}

		printf("%s\n", out.c_str());

	}

}