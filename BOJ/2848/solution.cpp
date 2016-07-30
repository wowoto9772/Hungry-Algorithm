#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

char str[103][13];

bool lnk['z' + 3]['z' + 3];

int in['z' + 3];
int s[103];

int main() {

	int n;
	scanf("%d", &n);

	bool used['z' + 3] = { 0 };

	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
		s[i] = strlen(str[i]);
		for (int j = 0; j < s[i]; j++) {
			used[str[i][j]] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int m = min(s[i], s[j]);
			for (int k = 0; k < m; k++) {
				if (str[i][k] != str[j][k]) {
					if (!lnk[str[i][k]][str[j][k]]) {
						lnk[str[i][k]][str[j][k]] = true;
						in[str[j][k]]++;
					}
					break;
				}
			}
		}
	}

	queue <int> q;

	int tot = 0;

	for (int i = 'a'; i <= 'z'; i++) {
		if (used[i]) {
			tot++;
			if (!in[i])q.push(i);
		}
	}

	bool MANY = false;

	if (q.size() >= 2)MANY = true;

	vector <int> x;

	while (!q.empty()) {
		int f = q.front(); q.pop();
		x.push_back(f);

		int flg = 0;
		for (int i = 'a'; i <= 'z'; i++) {
			if (lnk[f][i]) {
				in[i]--;
				if (!in[i]) {
					flg++;
					q.push(i);
				}
			}
		}

		if (flg > 1)MANY = true;

	}

	if (x.size() == tot) { // possible
		if (MANY)printf("?");
		else {
			for (int i = 0; i < x.size(); i++)printf("%c", x[i]);
		}
	}
	else {
		printf("!");
	}

}