//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//
//int a[23];
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
//		int tot = 0;
//
//		for (int i = 0; i < n; i++){
//			scanf("%d", &a[i]);
//			tot += a[i];
//		}
//
//		// 8 1 2 3 3 4 5 6 8 8
//		// 8 8 (2 6) (1 2 5)
//
//		int goal = tot / 4;
//
//		sort(a, a + n);
//
//		int l = 0, r = n - 1;
//
//		int m = 0;
//		int c = 0;
//
//		while (l <= r){
//			c += a[r];
//			r--;
//			if (c < goal){
//				while (l <= r){
//					c += a[l];
//					l++;
//					if (c > goal){
//						l--;
//						c -= a[l];
//						break;
//					}
//					else if(c == goal){
//						c = 0, m++;
//						break;
//					}
//				}
//			}
//			else if (c > goal){
//				r++;
//				c -= a[r];
//
//				bool flag = false;
//
//				while (l <= r){
//					c += a[l];
//					l++;
//					if (c > goal){
//						l--;
//						c -= a[l];
//						flag = true;
//						break;
//					}
//					else if (c == goal){
//						c = 0, m++;
//						break;
//					}
//				}
//
//				if (flag)break;
//			}
//			else{
//				c = 0, m++;
//				continue;
//			}
//		}
//
//		printf("%s\n", (m == 4) ? "yes" : "no");
//	}
//
//} // greedy : fail

//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std; 
//
//int goal;
//int lim;
//int a[23];
//int n;
//
//int dp[20][1 << 20];
//int len[1 << 20];
//
//vector <int> v;
//
//int dy(int c, int S){
//
//	if (c == 4){
//		if (S == lim)return 1;
//		return 0;
//	}
//
//	if (dp[c][S] != -1)return dp[c][S];
//
//	dp[c][S] = 0;
//
//	for (int i = 0; i < v.size(); i++){
//		int m = v[i];
//		if (S & m)continue; // duplicated
//		dp[c][S] = dy(c + 1, S | m);
//		if (dp[c][S])break;
//	}
//
//	return dp[c][S];
//
//}
//
//int main(){
//
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//
//		scanf("%d", &n);
//
//		int tot = 0;
//
//		for (int i = 0; i < n; i++){
//			scanf("%d", &a[i]);
//			tot += a[i];
//		}
//
//		// 8 1 2 3 3 4 5 6 8 8
//		// 8 8 (2 6) (1 2 5)
//
//		int goal = tot / 4;
//
//		sort(a, a + n);
//
//		lim = (1 << n) - 1;
//
//		for (int j = 0; j < 4; j++){
//			for (int i = 0; i < lim; i++){
//				dp[j][i] = -1;
//			}
//		}
//
//		v.clear();
//		for (int i = 0; i < lim; i++){
//			int x = 0;
//			for (int j = 0; j < n; j++){
//				if (i&(1 << j))x += a[j];
//				if (x > goal)break;
//			}
//			if (x == goal)v.push_back(i);
//		}
//
//		printf("%s\n", (dy(0, 0)) ? "yes" : "no");
//
//	}
//
//} // dp(1) : fail

#include <stdio.h>
#include <algorithm>

using namespace std;

int goal;
int lim;
int a[23];
int n;

int dp[1 << 20];

int dy(int c, int len, int S){

	if (len > goal)return 0;
	if (len == goal)len = 0;
	if (c == n){
		if (!len)return 1;
		return 0;
	}

	if (dp[S] != -1)return dp[S];

	dp[S] = 0;

	for (int i = 0; i < n && !dp[S]; i++){
		int m = (1 << i);
		if (S & m)continue;//duplicated
		dp[S] = dy(c + 1, len + a[i], S | m);
	}

	return dp[S];

}

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		scanf("%d", &n);

		int tot = 0;

		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			tot += a[i];
		}

		// 8 1 2 3 3 4 5 6 8 8
		// 8 8 (2 6) (1 2 5)

		goal = tot / 4;

		sort(a, a + n);

		lim = (1 << n) - 1;

		for (int i = 0; i < lim; i++){
			dp[i] = -1;
		}

		printf("%s\n", (dy(0, 0, 0)) ? "yes" : "no");

	}

} // dp(1) : fail