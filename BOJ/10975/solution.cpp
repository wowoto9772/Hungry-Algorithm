#include <stdio.h>
#include <vector>

using namespace std;

class BIT {
public:

	vector <int> T;
	int S;

	BIT(const int n) {
		S = n;
		T.resize(S + 1);
	}

	void Update(int p, int v) {
		while (p <= S) {
			T[p] += v;
			p += p & (-p);
		}
	}

	long long Sum(int p) {
		long long ret = 0;
		while (p > 0) {
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}

};

int e[53];

int main() {

	int n;
	scanf("%d", &n);

	BIT tree(2003);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &e[i]);
		e[i] += 1001;
		tree.Update(e[i], 1);
	}

	vector < int > down, up;

	for (int i = 1; i <= n; i++) {

		tree.Update(e[i], -1);


		bool pushed = false;

		for (int j = 0; j < up.size() && !pushed; j++) {
			if (e[i] < down[j]) {
				if (tree.Sum(down[j]) - tree.Sum(e[i]) == 0) {
					down[j] = e[i];
					pushed = true;
				}
			}
			else if (up[j] < e[i]) {
				if (tree.Sum(e[i]) - tree.Sum(up[j]) == 0) {
					up[j] = e[i];
					pushed = true;
				}
			}
		}

		if (!pushed) {
			down.push_back(e[i]);
			up.push_back(e[i]);
		}

	}

	printf("%d\n", up.size());


}