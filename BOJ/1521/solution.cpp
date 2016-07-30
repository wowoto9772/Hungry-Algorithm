#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;

map <vector <int>, double> chk;

double dy(vector <int> p) {

	if (chk.find(p) != chk.end())return chk[p];
	chk[p] = 0.0;

	double ret = 0;

	int c = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (p[i] > p[j]) {
				c++;
				swap(p[i], p[j]);
				ret += 1.0 + dy(p);
				swap(p[i], p[j]);
			}
		}
	}

	if (c == 0)return chk[p] = 0.0;
	else
		return chk[p] = ret / c;
}

double getExpected(vector <int> permutation) {
	return dy(permutation);
}

int main()
{
	scanf("%d", &n);

	vector <int> x;
	x.resize(n);

	for (int i = 0; i < n; i++)scanf("%d", &x[i]);

	printf("%.6lf\n", getExpected(x));
}