#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char tar[13];
int ctar['Z' + 3];
char cmp[13];

int main() {

	int n;
	scanf("%d", &n);

	n--;
	scanf("%s", tar);

	int s = strlen(tar);

	for (int i = 0; i < s; i++)ctar[tar[i]]++;

	int ans = 0;

	for (int i = 0; i < n; i++) {

		scanf("%s", cmp);

		int c['Z' + 3] = { 0 };

		int k = strlen(cmp);

		for (int j = 0; j < k; j++) {
			c[cmp[j]]++;
		}

		int flg = 0;

		for (int j = 'A'; j <= 'Z' && flg < 3; j++) {
			if (abs(c[j] - ctar[j]) == 1) {
				flg++;
			}
			else if (c[j] - ctar[j]) {
				flg += 3;
			}
		}

		if (flg <= 1) {
			ans++;
		}
		else if (flg == 2 && s == k)ans++;

	}

	printf("%d\n", ans);

}