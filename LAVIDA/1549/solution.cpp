//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//
//int I[10];
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n;
//		scanf("%d", &n);
//		for (int i = 1; i <= n; i++)scanf("%d", &I[i]);
//		sort(I + 1, I + 1 + n);
//
//		int l = 50, r = 50;
//		bool used[10] = { 0 };
//		int ans = 0;
//		for (int i = 1; i <= n; i++){
//			if (used[i])continue;
//			if (l == I[i]){
//				l = 0;
//			}
//			else if (r == I[i]){
//				r = 0;
//			}
//			else{
//				for (int j = n; j >= i + 1; j--){
//					if (used[j])continue;
//					if (l == I[j]){
//						used[j] = true;
//						l = 0;
//					}
//					else if (r == I[j]){
//						used[j] = true;
//						r = 0;
//					}
//				}
//				if (l > I[i]){
//					l -= I[i];
//					ans++;
//				}
//				else if (r > I[i]){
//					r -= I[i];
//					ans++;
//				}
//			}
//		}
//
//		printf("%d\n", ans);
//	}
//}

//#include <stdio.h>
//#include <algorithm>
//#include <memory.h>
//#define MAX 9191
//
//using namespace std;
//
//int n;
//int dp[53][53][1 << 8], I[10];
//int m(int a, int b){ return a < b ? a : b; }
//
//int dy(int l, int r, int c){
//	if (!l && !r)return 0;
//	if (dp[l][r][c] != -1)return dp[l][r][c];
//
//	dp[l][r][c] = MAX;
//
//	for (int i = 0; i < n; i++){
//		int nxt = (1 << i);
//		if (c & nxt)continue;
//		int k = I[i];
//		if (I[i] <= l){ // only one cut
//			if (I[i] == l)k = 0;
//			else
//				k = 1;
//			dp[l][r][c] = m(dp[l][r][c], dy(l - I[i], r, c | nxt) + k);
//		}
//		if (I[i] <= r){ // only one cut
//			if (I[i] == r)k = 0;
//			else
//				k = 1;
//			dp[l][r][c] = m(dp[l][r][c], dy(l, r - I[i], c | nxt) + k);
//		}
//	}
//
//	return dp[l][r][c];
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++)scanf("%d", &I[i]);
//		sort(I, I + n);
//
//		memset(dp, 0xff, sizeof(dp));
//
//		int ans = dy(50, 50, 0);
//		if (ans >= MAX)ans = 0;
//		else if (ans == 0)ans = 1;
//		printf("%d\n", ans);
//	}
//}

#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int I[10];
bool chk[10];
int s[10];
int ans;

void func(int c){
	if (c == n){
		bool a[101] = { 1, };
		int k = 0;
		a[k] = true;
		for (int i = 0; i < n; i++){
			k += I[s[i]];
			a[k] = true;
		}

		int tans = 0;
		for (int i = 0; i < 50; i++){
			if (a[i] && a[50 + i]){
				tans++;
			}
		}
		if (ans < tans)ans = tans;
		return ;
	}
	for (int i = 0; i < n; i++){
		if (chk[i])continue;
		chk[i] = true;
		s[c] = i;
		func(c+1);
		chk[i] = false;
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)scanf("%d", &I[i]);
		sort(I, I + n);

		ans = 0;

		func(0);

		printf("%d\n", ans);
	}
}

/*
	파이를 잘 배열해서 crossing 을 최대한 많이 나오게
*/