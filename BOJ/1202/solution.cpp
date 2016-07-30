#include <stdio.h>
#include <algorithm>
#include <set>

#define ll long long

using namespace std;

class ele{
public:
	int w;
	int c;
	ele(){}
	ele(int a, int b){ w = a, c = b; }
	bool operator<(const ele &A)const{
		return c > A.c;
	}
}I[300003];

int main(){

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++){
		int w, c;
		scanf("%d %d", &I[i].w, &I[i].c);
	}

	sort(I, I + n);

	multiset <int> bag;
	for (int i = 0; i < k; i++){
		int a;
		scanf("%d", &a);
		bag.insert(a);
	}

	ll ans = 0;
	int ind = 0;

	while (ind < n && !bag.empty()){

		ele itm = I[ind++];
		if (bag.lower_bound(itm.w) != bag.end()){
			bag.erase(bag.lower_bound(itm.w));
			ans += itm.c;
		}

	}

	printf("%lld\n", ans);
}