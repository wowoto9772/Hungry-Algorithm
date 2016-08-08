#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int e[103];

int main() {

	int t;
	scanf("%d", &t);

	int sum = 0;

	vector <int> sexy;

	int le = 0, ri = 0;

	while (t--) {

		int s;
		scanf("%d", &s);

		for (int i = 1; i <= s; i++)scanf("%d", &e[i]);

		for (int i = 1; i <= s / 2; i++) {
			le += e[i];
			ri += e[s + 1 - i];
		}

		if (s % 2)sexy.push_back(e[(s + 1) / 2]);

	}

	sort(sexy.begin(), sexy.end());

	bool cl = true;

	while (!sexy.empty()) {
		if (cl)le += sexy.back();
		else
			ri += sexy.back();
		cl ^= true;
		sexy.pop_back();
	}

	printf("%d %d\n", le, ri);

}