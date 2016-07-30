//#include <stdio.h>
//#include <memory.h>
//#define MAX 1000000007
//
//int dp[1002][10002];
//int N, A, B;
//int ux[1002], x[1002], ca[10002], cb[20002];
//
//int m(int a, int b){ return a < b ? a : b; }
//
//int dy(int c, int a){
//	if (c == N + 1)return 0;
//	if (dp[c][a] != -1)return dp[c][a];
//
//	dp[c][a] = MAX;
//
//	int o = x[c] > A - a ? A - a : x[c];
//
//	for (int i = o; i >= 0; i--){ // A's amount can use
//		int k = a + i;
//		if (ux[c] - k > B)continue;
//		dp[c][a] = m(dp[c][a], dy(c + 1, k) + ca[c] * i + cb[c] * (x[c] - i));
//	}
//
//	return dp[c][a];
//}
//
//int main()
//{
//	while (scanf("%d %d %d", &N, &A, &B) == 3){
//		if (!N && !A && !B)break;
//		for (int i = 1; i <= N; i++){
//			scanf("%d %d %d", &x[i], &ca[i], &cb[i]);
//			ux[i] = ux[i - 1] + x[i];
//		}
//
//		memset(dp, 0xff, sizeof(dp));
//
//		printf("%d\n", dy(1, 0));
//	}
//}

/*
5 30 25
10 10 15
10 20 10
10 15 10
10 50 11
10 20 15

4 30 30
10 20 10
10 20 10
10 100 1
10 70 4
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

int ab(int a){ return a < -a ? -a : a; }

class ele{
public:
	int g, a, b, n;
	bool operator<(const ele &A)const{
		return ab(g) > ab(A.g);
	}
}I[1003];

int main()
{
	int n, a, b;
	while (scanf("%d %d %d", &n, &a, &b) == 3){
		if (!n && !a && !b)break;

		for (int i = 0; i < n; i++){
			scanf("%d %d %d", &I[i].n, &I[i].a, &I[i].b);
			I[i].g = I[i].a - I[i].b;
		}

		sort(I, I + n);

		int cst = 0;
		
		for (int i = 0; i < n; i++){
			if (I[i].g > 0){
				if (b){
					int ub = b < I[i].n ? b : I[i].n;
					cst += I[i].b * ub;
					b -= ub;
					I[i].n -= ub;
				}
				if (I[i].n){
					int ua = a < I[i].n ? a : I[i].n;
					cst += I[i].a * ua;
					a -= ua;
					I[i].n -= ua;
				}
			}
			else{
				if (a){
					int ua = a < I[i].n ? a : I[i].n;
					cst += I[i].a * ua;
					a -= ua;
					I[i].n -= ua;
				}
				if (I[i].n){
					int ub = b < I[i].n ? b : I[i].n;
					cst += I[i].b * ub;
					b -= ub;
					I[i].n -= ub;
				}
			}
		}

		printf("%d\n", cst);
	}
}