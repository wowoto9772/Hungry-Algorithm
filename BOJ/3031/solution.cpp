#include <stdio.h>
#include <string.h>

#include <vector>

using namespace std;

char str[1003];

int a[5];

bool ended;

void make(int c, const vector <int> &v) {

	if (c == v.size()) {

		if (!ended) {
			if ((a[0] == a[1] + a[2] + a[3]) && (a[1] * 3 + a[2] == a[4])) {
				for (int l = 0; l < 5; l++)printf("%d ", a[l]);
				ended = true;
			}
		}

		return;

	}

	if (ended)return;

	if (v[c] == 4) {
		a[4] = a[1] * 3 + a[2];
		make(c + 1, v);
	}
	else {

		for (int i = 0; i < 300 && !ended; i++) {
			a[v[c]] = i;
			if (v[c] >= 1) {
				int k = 0;
				for (int j = 1; j <= v[c]; j++)k += a[j];
				if (a[0] < k)return;
			}
			make(c + 1, v);
		}

	}

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		vector <int> v;

		for (int i = 0; i < 5; i++) {
			scanf("%s", str);
			if (!strcmp(str, "?")) {
				a[i] = -1;
				v.push_back(i);
			}
			else
				sscanf(str, "%d", &a[i]);
		}

		ended = false;
		make(0, v);

		if (ended)printf("\n");

	}

}