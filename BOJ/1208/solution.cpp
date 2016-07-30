//#include <stdio.h>
//#define ll long long
//#define MID (4000000)
//ll dp[MID * 2 + 3][2];
//
//int main(){
//
//	int n, s;
//	scanf("%d %d", &n, &s);
//
//	dp[MID][0] = 1;
//
//	for (int i = 0; i < n; i++){
//		int a;
//		scanf("%d", &a);
//
//		int c = i % 2;
//		int n = !c;
//		for (int j = 0; j <= MID * 2; j++)dp[j][n] = dp[j][c];
//		for (int j = 0; j <= MID * 2; j++){
//			if (dp[j][c]){
//				dp[j + a][n] += dp[j][c];
//			}
//		}
//	}
//
//	printf("%lld\n", dp[MID + s][!(n%2)]);
//
//} // dp TLE

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int cnt(vector <int> &p, int cmp){
	int lo = lower_bound(p.begin(), p.end(), cmp) - p.begin();
	int hi = upper_bound(p.begin(), p.end(), cmp) - p.begin();
	hi--;

	if (lo <= hi){
		return hi - lo + 1;
	}

	return 0;
}
int a[23], b[23];

int main(){

	int n, s;
	scanf("%d %d", &n, &s);

	int g = n / 2;
	int h = n - g;

	for (int i = 0; i < g; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < h; i++){
		scanf("%d", &b[i]);
	}


	vector <int> p, q;
	for (int i = 1; i < (1 << g); i++){
		int c = 0;
		for (int j = 0; j < g; j++){
			if (i&(1 << j))c += a[j];
		}
		p.push_back(c);
	}
	for (int i = 1; i < (1 << h); i++){
		int c = 0;
		for (int j = 0; j < h; j++){
			if (i&(1 << j))c += b[j];
		}
		q.push_back(c);
	}

	sort(p.begin(), p.end());
	sort(q.begin(), q.end());

	ll ans = 0;

	for (int i = 0; i < q.size(); i++){
		int c = q[i];
		int cmp = s - c;

		ans += cnt(p, cmp);
	}

	ans += cnt(p, s) + cnt(q, s);

	printf("%lld\n", ans);
}