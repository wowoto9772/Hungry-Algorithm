#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int lis(const vector <int> &a){
	vector <int> b;
	for (auto &n : a){
		auto lo = lower_bound(b.begin(), b.end(), n);
		if (lo == b.end()){
			b.push_back(n);
		}
		else{
			*lo = n;
		}
	}return b.size();
} 

int main()
{
	int n;
	scanf("%d", &n);

	vector <int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	int le = lis(a);

	printf("%d\n", le);

}
