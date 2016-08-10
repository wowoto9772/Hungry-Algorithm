#include <stdio.h>

#include <vector>

using namespace std;

vector <int> uwsh;
vector <int> wsh;
vector <int> out;

int main() {

	int n;
	scanf("%d", &n);

	for (int i = n; i >= 1; i--)uwsh.push_back(i);

	while (out.size() != n) {

		int t, k;

		scanf("%d %d", &t, &k);

		for (int i = 1; i <= k; i++) {

			if (t == 1) {
				wsh.push_back(uwsh.back());
				uwsh.pop_back();
			}
			else {
				out.push_back(wsh.back());
				wsh.pop_back();
			}


		}

	}

	for (int i = n - 1; i >= 0; i--)printf("%d\n", out[i]);

}