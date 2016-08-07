#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> slice(const vector <int> &v, int a, int b) {
	return vector <int>(v.begin() + a, v.begin() + b);
}

void Consist(const vector <int> &pre, const vector <int> &in) {
	int S = pre.size();
	if (!S)return;
	char root = pre[0];

	int L = find(in.begin(), in.end(), root) - in.begin();
	int R = S - 1 - L;
	Consist(slice(pre, 1, L + 1), slice(in, 0, L));
	Consist(slice(pre, L + 1, S), slice(in, L + 1, S));
	printf("%d ", root);
}

int main()
{

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		vector <int> pre(n), in(n);

		for (int i = 0; i < n; i++)scanf("%d", &pre[i]);
		for (int i = 0; i < n; i++)scanf("%d", &in[i]);

		Consist(pre, in);
		printf("\n");
	}

}