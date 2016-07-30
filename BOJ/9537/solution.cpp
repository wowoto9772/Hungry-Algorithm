//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//
//#define ll long long
//
//using namespace std;
//
//ll gcd(ll a, ll b){
//
//	ll m = 1LL;
//
//	while (m){
//		m = a % b;
//		a = b;
//		b = m;
//	}
//
//	return a;
//}
//
//ll a[100003];
//
//int main(){
//
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//
//		int n;
//		scanf("%d", &n);
//
//		vector <ll> A;
//		vector <int> C;
//
//		for (int i = 0; i < n; i++){
//			scanf("%lld", &a[i]);
//			if (i){
//				if (A.back() == a[i]){
//					C.back()++;
//				}
//				else{
//					A.push_back(a[i]), C.push_back(1);
//				}
//			}
//			else{
//				A.push_back(a[i]);
//				C.push_back(1);
//			}
//		}
//
//		ll ans = 0;
//		ll tmp = A[0];
//		ll cnt = C[0];
//
//		if (cnt != 1)ans = cnt * A[0];
//
//		for (int i = 1; i < A.size(); i++){
//			ll ntmp = gcd(tmp, A[i]);
//			cnt += C[i];
//
//			if (ntmp * cnt > ans){
//				ans = ntmp * cnt;
//				tmp = ntmp;
//			}
//			else{
//				ntmp = gcd(A[i - 1], A[i]);
//				cnt = C[i - 1] + C[i];
//				if (ntmp * cnt > ans){
//					ans = ntmp * cnt;
//					tmp = ntmp;
//				}
//				else{
//					tmp = A[i];
//					cnt = C[i];
//				}
//			}
//		}
//
//		printf("%lld\n", ans);
//	}
//}

#include <stdio.h>
#include <algorithm>

#define ll long long

using namespace std;

ll gcd(ll a, ll b){

	ll m = 1LL;

	while (m){
		m = a % b;
		a = b;
		b = m;
	}

	return a;
}

ll a[100003];

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++){
			scanf("%lld", &a[i]);
		}

		ll ans = 0;

		for (int i = 0; i < n; i++){
			int l = i + 1, r = n - 1, m;

			while (l <= r){
				m = (l + r) / 2;
				ll tmp = a[i];
				for (int j = i + 1; j <= m; j++){
					tmp = gcd(tmp, a[j]);
					if (tmp == 1)break;
				}
				
				ll cmp = tmp * (m - i + 1);

				if (ans < cmp){
					ans = cmp;
					l = m + 1;
				}
				else
					r = m - 1;
			}
		}

		printf("%lld\n", ans);
	}
}