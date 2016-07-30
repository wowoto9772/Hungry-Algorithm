//#include <stdio.h>
//#include <queue>
//
//using namespace std;
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n, m, k;
//		scanf("%d %d %d", &n, &m, &k);
//
//		int d[12][12] = { 0 };
//
//		for (int i = 1; i <= m; i++){
//			int a, b;
//			scanf("%d %d", &a, &b);
//			d[a][b]++;
//		}
//
//		queue <int> A, C;
//		queue <long long> X;
//		A.push(0), C.push(0), X.push(1);
//
//		long long ans = 0;
//
//		while (!A.empty()){
//			int a = A.front(), c = C.front();
//			long long x = X.front();
//
//			A.pop(), C.pop(), X.pop();
//
//			if (c == k){
//				if (a == 0){
//					ans += x;
//					ans %= 1000000000;
//				}
//				continue;
//			}
//
//			for (int i = 0; i < n; i++){
//				if (d[a][i]){
//					x *= d[a][i];
//					x %= 1000000000;
//					A.push(i), C.push(c + 1), X.push(x);
//				}
//			}
//		}
//
//		printf("%lld\n", ans);
//	}
//}

#include <stdio.h>
#include <memory.h>

int N, M, K;
long long d[12][12];
long long dp[13][2003];

long long dy(int c, int k){
	if (dp[c][k] != -1)return dp[c][k];

	dp[c][k] = 0;

	for (int i = 0; i < N; i++){
		if (d[c][i]){
			dp[c][k] += d[c][i] * dy(i, k - 1);
			dp[c][k] %= 1000000000;
		}
	}

	return dp[c][k];
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d %d", &N, &M, &K);

		memset(d, 0, sizeof(d));

		for (int i = 1; i <= M; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			d[a][b]++;
		}

		memset(dp, 0xff, sizeof(dp));

		for (int i = 1; i < N; i++)dp[i][0] = 0;
		dp[0][0] = 1;

		printf("%lld\n", dy(0, K));
	}
}