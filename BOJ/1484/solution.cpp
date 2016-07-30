#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int g;
	scanf("%d", &g);

	vector <int> v;

	for (int i = 1; i <= (g / i); i++) {
		if (g%i)continue;

		int l = i, r = g/i;

		int a = (l + r) / 2;
		int b = -l + a;

		if (b <= 0)break;

		if ((a - b) * (a + b) == g) {
			v.push_back(a);
		}
	}

	sort(v.begin(), v.end());

	if (v.empty())printf("-1\n");
	else {
		for (int i = 0; i < v.size(); i++)printf("%d\n", v[i]);
	}

}