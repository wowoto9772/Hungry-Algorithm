#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int n;

void swp(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

map <vector <int>, double> chk;
double dy(vector <int> p){
	if (chk.count(p) != 0)return chk[p];
	chk[p] = 0.0;

	double ret = 0;

	int c = 0;
	for (int i = 0; i<n; i++){
		for (int j = i + 1; j<n; j++){
			if (p[i] > p[j]){
				c++;
				swp(&p[i], &p[j]);
				ret += 1.0 + dy(p);
				swp(&p[i], &p[j]);
			}
		}
	}

	if (c == 0)return chk[p] = 0.0;
	else
		return chk[p] = ret / c;
}

double getExpected(vector <int> permutation){
	//chk.clear();
	return dy(permutation);
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d", &n);

		vector <int> x;
		x.resize(n);
		for (int i = 0; i < n; i++)scanf("%d", &x[i]);

		printf("%.5lf\n", getExpected(x));
	}
}