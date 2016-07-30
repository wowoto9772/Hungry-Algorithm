#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ele {
public:

	string c;
	int v;

	ele() {}
	ele(string c_, int v_) { c = c_, v = v_; }

	bool operator<(const ele &A)const {
		return c < A.c;
	}
};

string d[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	if (n > m) {
		int t = n;
		n = m;
		m = t;
	}

	vector <ele> out;

	for (int i = n; i <= m; i++) {

		string tmp = d[i % 10];

		int j = i % 10;

		if (i / 10)tmp = d[i / 10] + " " + tmp;

		out.emplace_back(tmp, i);
	}

	sort(out.begin(), out.end());

	int c = 0;

	for (int i = 0; i < out.size(); i++) {
		printf("%d ", out[i].v);
		c++;

		if (c == 10) {
			c = 0;
			printf("\n");
		}
	}

}