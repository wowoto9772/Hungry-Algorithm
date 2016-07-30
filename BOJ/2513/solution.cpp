#include <stdio.h>
#include <algorithm>

using namespace std;

class ele{
public:
	int p, c;
	bool operator<(const ele &A)const{
		return p < A.p;
	}
}I[30003];

int main(){
	int n, k, s;
	scanf("%d %d %d", &n, &k, &s);

	for (int i = 1; i <= n; i++){
		scanf("%d %d", &I[i].p, &I[i].c);
	}

	sort(I + 1, I + 1 + n);

	// right
	int l = 1, r = n, p = 0;
	int ans = 0;
	bool last = false;

	while (I[r].p >= s && r >= 1){
		last = false;
		ans += I[r].p - s; // go rightmost
		int c = 0;
		int nr = r, p = I[r].p;
		while (I[nr].p >= s && nr >= 1){
			ans += p - I[nr].p; // go 1 left
			if (I[nr].c + c <= k){
				c += I[nr].c;
				p = I[nr].p;
				nr--;
			}
			else{
				I[nr].c -= k - c;
				ans += I[nr].p - s; // return to base
				c = 0;
				if (I[nr].c >= k){ // cycle
					ans += (I[nr].p - s) * 2 * (I[nr].c / k);
					I[nr].c %= k;
					if (!I[nr].c)nr--;
				}
				last = true;
				break;
			}
		}
		if (!last)ans += p - s;
		r = nr;
	}

	while (I[l].p <= s && l <= n){
		last = false;
		ans += s - I[l].p;
		int c = 0;
		int nl = l, p = I[l].p;
		while (I[nl].p <= s && nl <= n){
			ans += I[nl].p - p; // go leftmost
			if (I[nl].c + c <= k){
				c += I[nl].c;
				p = I[nl].p;
				nl++;
			}
			else{
				I[nl].c -= k - c;
				ans += s - I[nl].p; // go return to base
				c = 0;
				if (I[nl].c >= k){ // cycle
					ans += (s - I[nl].p) * 2 * (I[nl].c / k);
					I[nl].c %= k;
					if (!I[nl].c)nl++;
				}
				last = true;
				break;
			}
		}
		if (!last)ans += s - p;
		l = nl;
	}


	printf("%d\n", ans);
}