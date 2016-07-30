#include <stdio.h>
#include <limits.h>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

class ele{
public:
	int le, ri;
	bool operator<(const ele &A)const{
		if (ri == A.ri)return ri > A.ri;
		return ri < A.ri;
	}
}R[500003];

int lo[500003];

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d %d", &R[i].le, &R[i].ri);
	}

	sort(R + 1, R + 1 + n);

	lo[n] = R[n].le;
	for (int i = n - 1; i >= 1; i--){
		lo[i] = min(lo[i + 1], R[i].le);
	}

	ll gap = INT_MAX;
	ll acc = 0;
	for (int i = 1; i <= n; i++){
		ll g = min(acc + lo[i], // acc + current's lowest
			acc + gap + R[i].ri); // conversion le to ri in (1 ~ i-1)
		printf("%lld\n", g);
		acc += R[i].ri;
		if (gap > R[i].le - R[i].ri)gap = R[i].le - R[i].ri;
	}

}