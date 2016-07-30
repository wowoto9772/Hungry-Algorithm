#include <stdio.h>
#include <algorithm>
#include <vector>

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
} // no duplicated 1 2 3 3 5 ==> 1 2 3 5

int main(){

	int n;
	scanf("%d", &n);

	vector <int> a(n);

	for (int i = 0; i < n; i++)scanf("%d", &a[i]);

	printf("%d\n", lis(a));

}