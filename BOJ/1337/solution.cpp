#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int e[10003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &e[i]);
	}

	sort(e + 1, e + 1 + n);

	int ans = 5;

	for (int i = 1; i <= n; i++) {

		vector <int> sexy;

		for (int j = i; j <= i + 4 && j <= n; j++) {
			sexy.push_back(e[j]);
		}

		sort(sexy.begin(), sexy.end());

		for (int i = 0; i < sexy.size(); i++) {

			int p = sexy[i];

			bool chk[5] = { true };

			for (int j = i + 1; j < sexy.size(); j++) {

				int x = sexy[j] - p;

				if (x <= 4)chk[x] = true;

			}

			int c = 0;
			for (int j = 0; j < 5; j++) {
				c += chk[j];
			}

			ans = min(ans, 5 - c);
		}

	}


	printf("%d\n", ans);

}