#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

#define ll long long

int x[13], y[13];
ll xyr[13];
ll S;
int n;

void ps(int cur, int px, int py, ll pxyr, int dup, bool plus){
	if (px + py >= pxyr)return;
	if (cur < n){
		ps(cur + 1, px, py, pxyr, dup, plus);
		ps(cur + 1, max(px, x[cur]), max(py, y[cur]), min(pxyr, xyr[cur]), dup + 1, !plus);
	}
	else{
		if (pxyr != INT_MAX){
			ll r = (pxyr - (px + py));
			S += r*r*(plus ? 1LL : -1LL) * (1 << dup) >> 1;
		}
	}
}

int main(){

	scanf("%d", &n);

	for (int i = 0; i < n; i++){

		scanf("%d %d %lld", &x[i], &y[i], &xyr[i]);

		xyr[i] += x[i] + y[i];

	}

	ps(0, 0, 0, INT_MAX, 0, false);

	printf("%lld.%d\n", S / 2, (S % 2) ? 5 : 0);

}

// 3C1 + 3C3 = 3C0 + 3C2 = 4
// 4C1 + 4C3 = 4C0 + 4C2 + 4C4 = 8
// 5C1 + 5C3 + 5C5 = 5C0 + 5C2 + 5C4 = 16