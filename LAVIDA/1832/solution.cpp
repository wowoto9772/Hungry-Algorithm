//#include <stdio.h>
//#include <memory.h>
//
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int dp[103][203][203];
//int d2[103][2];
//int I[103], n;
//
//int m(int a, int b){ return a < b ? a : b; }
//
//class ele{
//public:
//	int a, i;
//	bool operator<(const ele &A)const{
//		if (a == A.a)return i < A.i;
//		return a < A.a;
//	}
//};
//
//int dy(int i, int s, int e){
//	if (i + 1 > n)return e - s + 1;
//	if (dp[i][s][e] != -1)return dp[i][s][e];
//
//	int tmp;
//	dp[i][s][e] = 200;
//
//	if (I[i + 1] <= I[d2[s][0]]){
//		tmp = d2[s][0];
//		d2[s][0] = i + 1;
//		dp[i][s][e] = dy(i + 1, s, e);
//		d2[s][0] = tmp;
//		d2[s - 1][0] = d2[s - 1][1] = i + 1;
//		return dp[i][s][e] = m(dp[i][s][e], dy(i + 1, s - 1, e));
//	}
//	if (I[i + 1] >= I[d2[e][1]]){
//		tmp = d2[e][1];
//		d2[e][1] = i + 1;
//		dp[i][s][e] = dy(i + 1, s, e);
//		d2[e][1] = tmp;
//		d2[e + 1][0] = d2[e + 1][1] = i + 1;
//		dp[i][s][e] = m(dp[i][s][e], dy(i + 1, s, e + 1));
//		return dp[i][s][e];
//	}
//
//
//	for (int c = s; c < e; c++){
//		if (I[d2[c][1]] <= I[i + 1] && I[i + 1] <= I[d2[c + 1][0]]){
//			tmp = d2[c][1];
//			d2[c][1] = i + 1;
//			dp[i][s][e] = m(dp[i][s][e], dy(i + 1, s, e));
//			d2[c][1] = tmp;
//			break;
//		}
//	}
//
//	if (s == e){
//		if (I[d2[s][0]] <= I[i + 1] && I[i + 1] <= I[d2[s][1]]){
//			d2[s][1] = i + 1;
//			d2[e + 1][0] = d2[e + 1][1] = d2[s][1];
//			return dp[i][s][e] = dy(i + 1, s, e + 1);
//		}
//	}
//
//	return dp[i][s][e];
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		scanf("%d", &n);
//
//		for (int i = 1; i <= n; i++)scanf("%d", &I[i]);
//
//		memset(dp, 0xff, sizeof(dp));
//
//		d2[100][0] = d2[100][1] = 1;
//		printf("%d\n", dy(1, 100, 100));
//	}
//}

#include <stdio.h>
#include <memory.h>

using namespace std;

int I[103], n;
int d[103][2][103]; // start is i, increasing 1, k-th element

int m(int a, int b){ return a < b ? a : b; }

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)scanf("%d", &I[i]);
	}
}