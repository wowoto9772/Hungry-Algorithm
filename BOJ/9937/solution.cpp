//#include <stdio.h>
//#include <algorithm>
//#define ll long long
//#define mod 1000000007LL
//
//using namespace std;
//
//class ele{
//public:
//	int dx, dy;
//	ele(){}
//	ele(int a, int b){ dx = a, dy = b; }
//	bool operator<(const ele &A)const{
//		if (dx == A.dx)return dy < A.dy;
//		return dx < A.dx;
//	}
//	bool operator == (const ele &A)const{
//		if (dx == A.dx && dy == A.dy)return true;
//		return false;
//	}
//}I[300003];
//
//int gcd(int a, int b){
//	int m = 1;
//	while (m){
//		m = a  % b;
//		a = b;
//		b = m;
//	}return a;
//}
//
//int main(){
//
//	int n;
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++){
//		int a, b, x;
//		scanf("%d %d %d", &a, &b, &x);
//		int g = gcd(a, b);
//		a /= g, b /= g;
//		I[i] = ele(a, b);
//	}
//
//	sort(I, I + n);
//
//	ll g = n;
//	ll tot = g * (g - 1) * (g - 2) / 6; // n C 3
//
//	tot %= mod;
//
//	for (int i = 0; i < n; i++){
//		int lo = lower_bound(I, I + n, I[i]) - I;
//		int hi = upper_bound(I, I + n, I[i]) - I;
//		hi--;
//		g = hi - lo + 1;
//		tot -= g * (g - 1) * (g - 2) / 6; // 3 parallel
//
//		g = g * (g - 1) / 2;
//
//		tot -= g * (lo + (n - 1 - hi)); // 2 parrallel * 1 point
//
//		if (tot < 0)tot += mod;
//
//		i = hi;
//	}
//
//	printf("%lld\n", tot);
//
//}

#include <stdio.h>
#include <algorithm>
#include <vector>

#define ll long long
#define mod 1000000007LL

using namespace std;

int gcd(int a, int b){
	int m = 1;
	while (m){
		m = a  % b;
		a = b;
		b = m;
	}return a;
}

pair<int, int> my[300003];

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		int a, b, x;
		scanf("%d %d %d", &a, &b, &x);
		if (a && b){
			int g = gcd(a, b);
			a /= g, b /= g;
			my[i] = make_pair(a, b);
		}
		else{
			if (a)a = 1;
			if (b)b = 1;
			my[i] = make_pair(a, b);
		}
	}

	sort(my, my+n);

	ll g = n;
	ll tot = g * (g - 1) * (g - 2) / 6; // n C 3

	for (int i = 0; i < n; i++){
		
		int lo = lower_bound(my, my + n, my[i]) - my;
		int hi = upper_bound(my, my + n, my[i]) - my;

		hi--;
		g = hi - lo + 1;
		tot -= g * (g - 1) * (g - 2) / 6; // 3 parallel

		g = g * (g - 1) / 2;

		tot -= g * (lo + (n - 1 - hi)); // 2 parrallel * 1 point

		i = hi;
	}

	printf("%lld\n", tot % mod);

}