//#include <stdio.h>
//#include <limits.h>
//#include <algorithm>
//#define ll long long
//
//using namespace std;
//
//int I[5003];
//
//ll A(ll a){ return a < -a ? -a : a; }
//ll mm(ll a, ll b){ return a < b ? a : b; }
//
//int main()
//{
//	int n;
//	while (scanf("%d", &n) == 1){
//
//		for (int i = 1; i <= n; i++)scanf("%d", &I[i]);
//
//		sort(I + 1, I + 1 + n);
//
//		int L = 1, R = n;
//
//		ll ans = INT_MAX * 3LL;
//		int x = -1, y = -1, z = -1;
//
//		for (int L = 1; ans && L <= n - 2; L++){
//			for (int R = L + 2; ans && R <= n; R++){
//				int l = L + 1, r = R - 1, m;
//				ll cmp = I[L] + I[R];
//
//				while (l <= r && ans){
//					m = (l + r) / 2;
//					ll cnt = cmp + I[m];
//					ll k = A(cnt);
//					if (cnt < 0)l = m + 1;
//					else if (cnt > 0){
//						r = m - 1;
//					}
//					if (k < ans){
//						ans = k;
//						x = L, y = m, z = R;
//					}
//				}
//			}
//		}
//
//		printf("%d %d %d\n", I[x], I[y], I[z]);
//	}
//
//}

#include <stdio.h>
#include <limits.h>
#include <algorithm>
#define ll long long

using namespace std;

ll I[5003];

ll A(ll a){ return a < -a ? -a : a; }

int main()
{
	int n;
	while (scanf("%d", &n) == 1){

		for (int i = 1; i <= n; i++)scanf("%lld", &I[i]);

		sort(I + 1, I + 1 + n);

		ll ans = INT_MAX * 3LL;
		int x = -1, y = -1, z = -1;

		for (int M = 2; ans && M <= n - 1; M++){
			int L = M - 1, R = M + 1;
			while (L >= 1 && R <= n && ans){
				ll cmp = I[L] + I[M] + I[R];
				if (ans > A(cmp)){
					ans = A(cmp);
					x = L, y = M, z = R;
				}
				if (cmp > 0)L--;
				else if (cmp < 0)R++;
			}
		}

		printf("%lld %lld %lld\n", I[x], I[y], I[z]);
	}

}