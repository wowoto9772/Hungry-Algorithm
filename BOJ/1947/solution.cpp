//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	int n;
//	while (scanf("%d", &n) == 1) {
//
//		int str[13] = { 0 };
//		for (int i = 0; i < n; i++)str[i] = i;
//
//		int ans = 0;
//		while (next_permutation(str, str + n)) {
//			int flg = 0;
//			for (int i = 0; i < n; i++) {
//				if (str[i] == i) {
//					flg++;
//					break;
//				}
//			}
//			if (!flg)ans++;
//		}
//
//		printf("%d\n", ans);
//	}
//}


// perfect permutation | dearrangement permutation
#include <stdio.h>

#define ll long long
#define mod 1000000000

int n;
ll dp[1000003];

int main()
{
	scanf("%d", &n);

	dp[2] = 1;
	
	for (int i = 3; i <= n; i++) {
		dp[i] = ((i - 1) * (dp[i - 2] + dp[i - 1])) % mod;
	}

	printf("%lld\n", dp[n]);
}
