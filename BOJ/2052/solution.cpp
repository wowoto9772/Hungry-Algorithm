#include <stdio.h>
#include <string>

using namespace std;

string out[253];

int main() {

	out[0] = "5";

	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		int s = out[i - 1].size();
		int d = 0;
		for (int j = 0; j < s; j++) {
			d = d * 10 + out[i - 1][j] - '0';
			out[i] += (d / 2) + '0';
			d %= 2;
		}
		if (d) {
			d *= 10;
			out[i] += (d / 2) + '0';
		}
	}

	printf("0.%s\n", out[n-1].c_str());

}