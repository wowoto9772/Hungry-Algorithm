#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int s[150 * 150 + 3];

int main() {

	for (int i = 1; i <= 150; i++) {
		s[i*i] = i;
	}

	vector < pair <int, int> > v;
	
	for (int w = 1; w <= 150; w++) {
		for (int h = 1; h < w; h++) {
			v.emplace_back(w*w + h*h, h);
		}
	}

	sort(v.begin(), v.end());

	int w, h;
	while (scanf("%d %d", &h, &w) == 2) {

		if (!(w | h))break;

		int p = upper_bound(v.begin(), v.end(), make_pair(w*w + h*h, h)) - v.begin();

		printf("%d %d\n", v[p].second, s[(v[p].first - v[p].second * v[p].second)]);

	}

}