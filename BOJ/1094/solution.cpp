#include <stdio.h>
#include <vector>

using namespace std;

int main() {

	vector <int> stk;
	stk.push_back(64);

	int x;
	scanf("%d", &x);

	while (true) {
		int c = 0;
		for (int i = 0; i < stk.size(); i++)c += stk[i];
		if (c == x) {
			printf("%d\n", stk.size());
			break;
		}
		if (c - stk.back() + stk.back() / 2 >= x) {
			stk.back() /= 2;
		}
		else {
			stk.back() /= 2;
			stk.push_back(stk.back());
		}
	}

}